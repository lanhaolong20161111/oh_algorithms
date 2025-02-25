class Solution {
    int dx[4]={0,0,1,-1};           //水平方向偏移量
    int dy[4]={1,-1,0,0};           //垂直方向偏移量
    vector<vector<bool>> visited;
    int m,n;
    int ans;                        //存放答案
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        m=grid.size();n=grid[0].size();
        visited=vector<vector<bool>>(m,vector<bool>(n,false));
        ans=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {       //只有一个陆地
                    dfs(grid,i,j);
                    return ans;
                }
            }
        }
        return 0;
    }
    void dfs(vector<vector<int>>& grid,int x,int y) {
        if(visited[x][y]) return;
        visited[x][y]=true;
        for(int di=0;di<4;di++) {
            int nx=x+dx[di],ny=y+dy[di];
            if(nx<0 || nx>=m || ny<0 || ny>=n)		//(nx,ny)为边界
                ans++;
            else if(grid[nx][ny]==0)					//(nx,ny)为水域
                ans++;
            else dfs(grid,nx,ny);
        }
    }
};

