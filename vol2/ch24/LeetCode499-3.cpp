struct QNode {                  //优先队列中结点类型
    int r,c;
    int steps;
    QNode() {}
    QNode(int r1,int c1,int s1):r(r1),c(c1),steps(s1) {}
    bool operator<(const QNode&s) const {
        return steps>s.steps;         //按steps越小越优先出队
    }
};
class Solution {
    const int INF=0x3f3f3f3f;
    int dr[4]={1, 0, 0, -1};                //垂直方向偏移量
    int dc[4]={0, -1,1, 0};                 //水平方向偏移量
    vector<string> dirstr={"d","l","r","u"};    //方位：字典序最小
public:
string findShortestWay(vector<vector<int>>&maze,vector<int>&ball,vector<int>&hole) {
        int m=maze.size(),n=maze[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INF));
        vector<vector<string>> path(m,vector<string>(n,""));
        priority_queue<QNode> pqu;
        QNode e,e1;
        dist[ball[0]][ball[1]]=0;
        pqu.push(QNode(ball[0],ball[1],0));
        while(!pqu.empty()) {
            e=pqu.top(); pqu.pop();
            int r=e.r,c=e.c;
            for(int di=0;di<4;di++) {
                int nr=r,nc=c;
                int delta=0;
                while(nr+dr[di]>=0 && nr+dr[di]<m && nc+dc[di]>=0 
                    && nc+dc[di]<n && maze[nr+dr[di]][nc+dc[di]]==0) {
                    nr+=dr[di];
                    nc+=dc[di];
                    delta++;                        //走的步数增量
                    if(nr==hole[0] && nc==hole[1]) 
                        break;                      //找到洞时将其作为停靠点
                }
                int curdist=dist[r][c]+delta;
                string curpath=path[r][c]+dirstr[di];
                if (curdist<dist[nr][nc]) {          	//比较求最短路径
                    dist[nr][nc]=curdist;
                    path[nr][nc]=curpath;
                    pqu.push(QNode(nr,nc,dist[nr][nc]));
                }
                else if (curdist==dist[nr][nc]) {       //相同长度时
                    if(curpath<path[nr][nc]) {
                        path[nr][nc]=curpath;
                        pqu.push(QNode(nr,nc,dist[nr][nc]));
                    }
                }
            }
        }
        if(dist[hole[0]][hole[1]]==INF) return "impossible";
        else return path[hole[0]][hole[1]];
    }
};

