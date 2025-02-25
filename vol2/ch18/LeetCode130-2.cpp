class Solution {
    int dx[4]={0,0,1,-1};                       //水平方向偏移量
    int dy[4]={1,-1,0,0};                       //垂直方向偏移量
    int m,n;
    queue<pair<int,int>> qu;                //定义一个队列qu
public:
    void solve(vector<vector<char>>& board) { 
        m=board.size();                                     //行数
        n=board[0].size();                          //列数
        for (int i=0;i<m;i++) {                     //从最外面一圈找'O'
            for (int j=0;j<n;j++) {
                if ((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O') {
                    board[i][j]='$';        //用特殊字符'$'替换
                    qu.push(pair<int,int>(i,j));   //将最外面一圈的所有'O'进队
                }
             }
        }
        bfs(board);
        for (int i=0;i<m;i++) {                             //替换
            for (int j=0;j<n;j++) {
                if (board[i][j]=='$')
                    board[i][j]='O';
                else if (board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
    void bfs(vector<vector<char>>& board) {     //多起点广度优先遍历
        while(!qu.empty()) {                              //队不空时循环
            auto e=qu.front(); qu.pop();        //出队元素e
            int i=e.first,j=e.second;
            for (int di=0;di<4;di++) {
                int x=i+dx[di];                //求出di方位的相邻位置(x,y)
                int y=j+dy[di];
                if (x<0 || x>=m || y<0 || y>=n || board[x][y]!='O') 
                    continue;                      //超界或者不是'O'时跳过
                board[x][y]='$';
                qu.push(pair<int,int>(x,y));            //(x,y)进队
            }
        }
    }
};

