class Solution {
    int dx[4]={0,0,1,-1};                        //水平方向偏移量
    int dy[4]={1,-1,0,0};                       //垂直方向偏移量
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();                              //行数
        int n=grid[0].size();                           //列数
        if (m==0 || n==0) return 0;
        int ans=0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]=='1') {
                    ans++;                          //累计调用dfs的次数
                    bfs(grid,i,j);
                }
            }
        }
        return ans;
    }
    void bfs(vector<vector<char>>& grid,int i,int j) { //从(i,j)位置出发广度优先遍历
        queue<pair<int,int>> qu;                        //定义一个队列
        grid[i][j]='0';                                     //访问(i,j)
        qu.push(pair<int,int>(i,j));                //(i,j)进队
        while(!qu.empty()) {                            //队不空时循环
            auto e=qu.front(); qu.pop();                //出队元素e
            i=e.first; j=e.second;
            for (int di=0;di<4;di++) {
                int x=i+dx[di];                 //求出di方位的相邻位置(x,y)
                int y=j+dy[di];
                if (x<0 || x>=grid.size() || y<0 || y>=grid[0].size()) 
                        continue;               //超界时跳过
                if (grid[x][y]=='0')
                        continue;
                grid[x][y]='0';                 //访问(x,y)
                qu.push(pair<int,int>(x,y));            //(x,y)进队
            }
        }
    }
};

