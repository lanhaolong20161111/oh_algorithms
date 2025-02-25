struct QNode {                      //优先队列结点类型
    int x,y;                        //位置
    int g;
    double f,h;                   //启发式函数值
    bool operator<(const QNode &s) const {
        return f>s.f;              //f越小越优先出队
    }
};
class Solution {
    int dx[8]={0,0,-1,1,-1,1,-1,1};
    int dy[8]={-1,1,0,0,-1,-1,1,1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1) return 1;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        priority_queue<QNode> pqu;
        QNode e,e1;
        e.x=0;e.y=0;e.g=1;
        e.h=geth(0,0,n-1,n-1);
        e.f=e.g+e.h;
        pqu.push(e);
        visited[0][0]=true;
        while(!pqu.empty()) {
            e=pqu.top();pqu.pop();
            int x=e.x,y=e.y;
            if (x==n-1 && y==n-1) return e.g;
            for (int di=0;di<8;di++) {
                int nx=x+dx[di];
                int ny=y+dy[di];
                if (nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0) {
                    if(visited[nx][ny]) continue;
                    e1.x=nx;e1.y=ny;
                    e1.g=e.g+1;
                    e1.h=geth(nx,ny,n-1,n-1);
                    e1.f=e1.g+e1.h;
                    pqu.push(e1);
                    visited[nx][ny]=true;
                }
            } 
        }
        return -1;
    }
    double geth(int x,int y,int gx,int gy) { //计算启发式函数值
           return 0.4*(max(abs(gx-x),abs(gy-y)));
     } 
};

