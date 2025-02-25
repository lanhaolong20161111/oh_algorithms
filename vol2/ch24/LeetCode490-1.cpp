class Solution {
    int dr[4]={0,0,-1,1};            //水平方向偏移量
    int dc[4]={-1,1,0,0};            //垂直方向偏移量
    int m,n;
    vector<vector<bool>> visited;
    int sr,sc,tr,tc;
public:
    bool hasPath(vector<vector<int>>& maze,vector<int>& start,vector<int>& dest) {
        m=maze.size();n=maze[0].size();
        visited=vector<vector<bool>>(m,vector<bool>(n,false));
        sr=start[0]; sc=start[1];
        tr=dest[0]; tc=dest[1];
        visited[sr][sc]=true;
        return dfs(maze,sr,sc);
    }
    bool dfs(vector<vector<int>>& maze,int r,int c) {
        if (r==tr && c==tc)
            return true;
        else {
            for(int di=0;di<4;di++) {       //从(r,c)扩展
                int nr=r,nc=c;
                while(nr+dr[di]>=0 && nr+dr[di]<m && 
                        nc+dc[di]>=0 && nc+dc[di]<n  && 
                        maze[nr+dr[di]][nc+dc[di]]==0) {            //一直滚下去
                    nr+=dr[di];nc+=dc[di];
                }                            //按di方向滚到(nr,nc)
                if (visited[nr][nc]) continue;
                visited[nr][nc]=true;
                if(dfs(maze,nr,nc)) return true;
            }
            return false;
        }
    }
};

