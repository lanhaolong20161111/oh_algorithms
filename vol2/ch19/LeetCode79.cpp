class Solution {
    int dr[4]={0,0,1,-1};                    //按行方向的偏移量
    int dc[4]={1,-1,0,0};                       //按列方向的偏移量
    vector<vector<int>> visited;                  //访问标记数组
    bool ans;
 public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        visited=vector<vector<int>>(m,vector<int>(n,0));
        for(int r=0;r<m;r++) {
            for(int c=0;c<n;c++) {
                if (board[r][c]==word[0]) {
                    visited[r][c]=1;
                    ans=false;
                    dfs(board,word,r,c,1);						//i从1开始
                    if(ans) return true;
                    visited[r][c]=0;
                }
            }
        }
        return false;
    }
    void dfs(vector<vector<char>>&board,string&word,int r,int c,int i) {		//回溯算法
        if(i>=word.size())
            ans=true;
        else if(!ans) {
            for(int di=0;di<4;di++) {			//四周试探
                int nr=r+dr[di];    //求di方位的相邻位置[nr,nc]
                int nc=c+dc[di];
                if(nr<0 || nr>=board.size() || nc<0 || nc>=board[0].size())
                    continue;       //跳过无效的[nr,nc]
                if(visited[nr][nc]==1)
                    continue;       //跳过已经访问的[nr,nc]
                if(board[nr][nc]==word[i]) {
                    visited[nr][nc]=1;
                    dfs(board,word,nr,nc,i+1);
                    visited[nr][nc]=0;
                }
            }
        }
    }
};

