class Solution {
    int dx[4]={0,0,1,-1};           //ˮƽ����ƫ����
    int dy[4]={1,-1,0,0};           //��ֱ����ƫ����
    vector<vector<bool>> visited;
    int m,n;
    int ans;                        //��Ŵ�
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        m=grid.size();n=grid[0].size();
        visited=vector<vector<bool>>(m,vector<bool>(n,false));
        ans=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {       //ֻ��һ��½��
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
            if(nx<0 || nx>=m || ny<0 || ny>=n)		//(nx,ny)Ϊ�߽�
                ans++;
            else if(grid[nx][ny]==0)					//(nx,ny)Ϊˮ��
                ans++;
            else dfs(grid,nx,ny);
        }
    }
};

