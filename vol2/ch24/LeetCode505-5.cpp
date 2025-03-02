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
    int dr[4]={0,0,-1,1};            //水平方向偏移量
    int dc[4]={-1,1,0,0};            //垂直方向偏移量
public:
    int shortestDistance(vector<vector<int>>&maze,vector<int>& start,vector<int>& dest) {
        int m=maze.size(),n=maze[0].size();
        priority_queue<QNode> pqu;
        QNode e,e1;
        vector<vector<int>> dist(m,vector<int>(n,INF));
        vector<vector<bool>> S(m,vector<bool>(n,false));
        dist[start[0]][start[1]]=0;
        S[start[0]][start[1]]=true;
        e=QNode(start[0],start[1],0);
        pqu.push(e);
        while(!pqu.empty()) {
            e=pqu.top(); pqu.pop();
            int r=e.r,c=e.c,steps=e.steps;
            S[r][c]=true;                //将(r,c)添加到S集合中
            if(r==dest[0] && c==dest[1])    //找到目标直接返回
                return dist[r][c];
            for(int di=0;di<4;di++) {
                int nr=r,nc=c;
                int delta=0;
                while(nr+dr[di]>=0 && nr+dr[di]<m && nc+dc[di]>=0 && nc+dc[di]<n
                        && maze[nr+dr[di]][nc+dc[di]]==0) {  //按di方向滚到(nr,nc)
                    nr+=dr[di];
                    nc+=dc[di];
                    delta++;                    //走的步数增量
                }
                if(S[nr][nc]) continue;      //仅修改不在S中的位置
                if(dist[r][c]+delta<dist[nr][nc]) {     //边松弛
                    dist[nr][nc]=dist[r][c]+delta;
                    e1=QNode(nr,nc,dist[nr][nc]);
                    pqu.push(e1);
                }
            }
        }
        return -1;
    }
};

