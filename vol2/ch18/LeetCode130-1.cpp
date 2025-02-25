class Solution {
    int dx[4]={0,0,1,-1};                        //水平方向偏移量
    int dy[4]={1,-1,0,0};                        //垂直方向偏移量
    int m,n;
public:
    void solve(vector<vector<char>>& board) {
        m=board.size();                     //行数
        n=board[0].size();                  //列数
        for (int i=0;i<m;i++) {                  //从最外面一圈找到一个'O'
            for (int j=0;j<n;j++) {
                if ((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O') 
                    dfs(board,i,j);
            }
        }
        for (int i=0;i<m;i++) {                     //替换
            for (int j=0;j<n;j++) {
                if (board[i][j]=='$')
                    board[i][j]='O';
                else if (board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
    void dfs(vector<vector<char>>& board,int i,int j) {     //(i,j)位置出发深度优先遍历
        board[i][j]='$';
        for (int di=0;di<4;di++) {
            int x=i+dx[di];
            int y=j+dy[di];
            if (x<0 || x>=m || y<0 || y>=n || board[x][y]!='O') 
                continue;                                   //超界或者不是'O'时跳过
            dfs(board,x,y);
        }
    }
};

