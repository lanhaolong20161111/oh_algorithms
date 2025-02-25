class Solution {
    int dx[4]={0,0,1,-1};                        //水平方向偏移量
    int dy[4]={1,-1,0,0};                       //垂直方向偏移量
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();                      //行数
        int n=grid[0].size();                   //列数
        int ans=0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]=='1') {
                    ans++;                      //累计调用dfs的次数
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid,int i,int j) {  //从(i,j)位置出发深度优先遍历
        grid[i][j]='0';                                 //访问(i,j)
        for (int di=0;di<4;di++) {
            int x=i+dx[di];                             //求出di方位的相邻位置(x,y)
            int y=j+dy[di];
            if (x<0 || x>=grid.size() || y<0 || y>=grid[0].size()) 
                continue;                               //超界时跳过
            if (grid[x][y]=='0')
                continue;
            dfs(grid,x,y);
        }
    }
};

