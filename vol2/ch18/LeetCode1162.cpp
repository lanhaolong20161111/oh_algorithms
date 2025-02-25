class Solution {
    int dx[4]={0,0,1,-1};                        //水平方向偏移量
    int dy[4]={1,-1,0,0};                       //垂直方向偏移量
    queue<pair<int,int>> qu;
    vector<vector<bool>> visited;
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        visited=vector<vector<bool>>(n,vector<bool>(n,false));
        int cnt=0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]==1) {            //陆地单元
                    qu.push(pair<int,int>(i,j));
                    visited[i][j]=true;
                    cnt++;
                }
            }
        }
        if(cnt==n*n) return -1;     //全部为陆地的情况
        else return bfs(grid);
    }
    int bfs(vector<vector<int>>&grid) {    //多起点分层次广度优先搜索
        int n=grid.size();
        int step=0;
        while(!qu.empty()) {
            int cnt=qu.size();
            for(int i=0;i<cnt;i++) {
                auto e=qu.front();qu.pop();
                int x=e.first,y=e.second;
                for(int di=0;di<4;di++) {
                    int nx=x+dx[di];
                    int ny=y+dy[di];
                    if (nx<0 || nx>=n || ny<0 || ny>=n)
                        continue;
                    if(visited[nx][ny]) continue;		//跳过已访问的单元
                    if(grid[nx][ny]==1) continue;		//跳过陆地单元
                    visited[nx][ny]=true;
                    qu.push(pair<int,int>(nx,ny));
                }
            }
            step++;												//扩展层次增1
        }
        return step-1;
    }
};

