struct QNode {                                      //优先队列结点类型
    int r,c;                                        //当前位置
    int f,g,h;                                      //启发式函数值
    bool operator<(const QNode &s) const  {         //重载<关系函数
          return f>s.f;                             //f越小越优先出队
    }
};
class Solution {
    const int INF=0x3f3f3f3f;
    int dr[4]={1,0,0,-1};                //垂直方向偏移量
    int dc[4]={0,-1,1,0};                 //水平方向偏移量
    vector<string> dirstr={"d","l","r","u"};    //方位：字典序最小
public:
string findShortestWay(vector<vector<int>>&maze,vector<int>&ball,vector<int>&hole) {
        int m=maze.size(),n=maze[0].size();
        priority_queue<QNode> pqu;
        QNode e,e1;
        vector<vector<string>> path(m,vector<string>(n,""));       
        vector<vector<int>> minf(m,vector<int>(n,INF));
        minf[ball[0]][ball[1]]=0;
        e.r=ball[0];e.c=ball[1];
        e.g=0;e.h=geth(ball[0],ball[1],hole[0],hole[1]);
        e.f=e.g+e.h;
        pqu.push(e);
        minf[ball[0]][ball[1]]=0;
        while(!pqu.empty()) {
            e=pqu.top(); pqu.pop();
            int r=e.r,c=e.c;
            for(int di=0;di<4;di++) {
                int nr=r,nc=c;
                string curd=dirstr[di];
                int delta=0;
                while(nr+dr[di]>=0 && nr+dr[di]<m 
                        && nc+dc[di]>=0 && nc+dc[di]<n
                        && maze[nr+dr[di]][nc+dc[di]]==0) { //按di方向滚
                    nr+=dr[di];
                    nc+=dc[di];
                    delta++;                    //走的步数增量
                    if(nr==hole[0] && nc==hole[1]) 
                        break;                      //找到洞时将其作为停靠点
                }
                e1.r=nr;e1.c=nc;
                e1.g=e.g+delta;
                e1.h=geth(nr,nc,hole[0],hole[1]);
                e1.f=e1.g+e1.h;
                string curpath=path[r][c]+dirstr[di];
                if(e1.f<minf[nr][nc]) {         //当前路径的f更短
                    minf[nr][nc]=e1.f;
                    path[nr][nc]=curpath;
                    pqu.push(e1);
                }
                else if(e1.f==minf[nr][nc]) {       //f相同时
                    if(curpath<path[nr][nc]) {      //取字段序比小的路径
                        path[nr][nc]=curpath;
                        pqu.push(e1);
                    }
                }
            }
        }
        if(path[hole[0]][hole[1]]=="") return "impossible";
        else return path[hole[0]][hole[1]];
    }
    double geth(int x,int y,int gx,int gy) { //计算启发式函数值
        return abs(gx-x)+abs(gy-y);
    }
};
