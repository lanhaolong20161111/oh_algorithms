class Solution {
    int dx[4]={0,0,1,-1};                   //水平方向偏移量
    int dy[4]={1,-1,0,0};                   //垂直方向偏移量
    queue<pair<int,int>> qu;                                //定义一个队列qu
    vector<vector<bool>> visited;           //访问标记数组
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid[0].size();
     	visited=vector<vector<bool>>(n,vector<bool>(n,false));
        bool find=false;
        int x,y;
        for (int i=0;i<n;i++) {         //找到任意一个陆地(x,y)
            for (int j=0;j<n;j++) {
                if(grid[i][j]==1 && !find) {
                    find=true;
                    x=i; y=j;
                    break;
            }
        }
        if (find) break;
        }
        dfs(grid,x,y);
        return bfs(grid);
    }
    void dfs(vector<vector<int>>& grid,int x,int y) {          //DFS算法
     	visited[x][y]=1;
        if(grid[x][y]==1)                                      //(x,y)为陆地时进队
            qu.push(pair<int,int>(x,y));
        for (int di=0;di<4;di++) {
        	int nx=x+dx[di];
            int ny=y+dy[di];
        	if(nx<0 || nx>=grid.size() || ny<0 || ny>=grid[0].size())
            	continue;
            if (visited[nx][ny] || grid[nx][ny]==0)
            	continue;
            dfs(grid,nx,ny);
        }
    }
    int bfs(vector<vector<int>>& grid) {                       //分层次的BFS
        int ans=0;
        while (!qu.empty()) {
            int cnt=qu.size();                                  //求队列中元素个数cnt
            for (int i=0;i<cnt;i++) {               //处理一层的元素
                    auto e=qu.front(); qu.pop();       //出队元素e
                int x=e.first,y=e.second;
                for (int di=0;di<4;di++) {
                    int nx=x+dx[di];
                int ny=y+dy[di];
                                if(nx<0 || nx>=grid.size() || ny<0 || ny>=grid[0].size())
                                    continue;
                if(visited[nx][ny])
                                    continue;
                if(grid[nx][ny]==1)
                    return ans;
                qu.push(pair<int,int>(nx,ny));;         //(nx,ny)进队
                visited[nx][ny]=true;
                }
            }
            ans++;
        }
        return ans;
    }
};

