class Solution {
    int dx[4]={0,0,1,-1};                   //ˮƽ����ƫ����
    int dy[4]={1,-1,0,0};                   //��ֱ����ƫ����
    queue<pair<int,int>> qu;                                //����һ������qu
    vector<vector<bool>> visited;           //���ʱ������
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid[0].size();
     	visited=vector<vector<bool>>(n,vector<bool>(n,false));
        bool find=false;
        int x,y;
        for (int i=0;i<n;i++) {         //�ҵ�����һ��½��(x,y)
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
    void dfs(vector<vector<int>>& grid,int x,int y) {          //DFS�㷨
     	visited[x][y]=1;
        if(grid[x][y]==1)                                      //(x,y)Ϊ½��ʱ����
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
    int bfs(vector<vector<int>>& grid) {                       //�ֲ�ε�BFS
        int ans=0;
        while (!qu.empty()) {
            int cnt=qu.size();                                  //�������Ԫ�ظ���cnt
            for (int i=0;i<cnt;i++) {               //����һ���Ԫ��
                    auto e=qu.front(); qu.pop();       //����Ԫ��e
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
                qu.push(pair<int,int>(nx,ny));;         //(nx,ny)����
                visited[nx][ny]=true;
                }
            }
            ans++;
        }
        return ans;
    }
};

