class Solution {
public:
    int dx[8]={0,1,0,-1,1,1,-1,-1};  //水平方向偏移量
    int dy[8]={1,0,-1,0,1,-1,1,-1};  //垂直方向偏移量
    int m,n;
   vector<vector<char>> updateBoard(vector<vector<char>>& board,vector<int>&click) {
        m=board.size();n=board[0].size();
        int x=click[0],y=click[1];
        if (board[x][y]=='M')       //规则1
            board[x][y]='X';
        else
            dfs(board,x,y);
        return board;
    }
    int Count(vector<vector<char>>& board,int x,int y) {        //求(x,y)相邻的'M'个数
        int nx,ny,cnt=0;
            for(int di=0;di<8;di++) {                       //遍历8个方位
                nx=x+dx[di];
                ny=y+dy[di];
                if(nx<0 || nx>=m || ny<0 || ny>=n)      //忽略超界的位置
                    continue;
                if(board[nx][ny]=='M') cnt++;           //求相邻地雷个数cnt
            }
        return cnt;
    }
    void dfs(vector<vector<char>>& board,int x,int y) {     //深度优先搜索
        int cnt=Count(board,x,y);
        if(cnt==0) {                                //cnt=0:规则2
            board[x][y]='B';
            for (int di=0;di<8;di++) {
                int nx=x+dx[di];
                int ny=y+dy[di];
                if(nx<0 || nx>=m || ny<0 || ny>=n)      //忽略超界的位置
                    continue;
                if(board[nx][ny]=='B')    //为'B'时跳过因为'B'之前被点击的时候已经被扩展过了
                    continue;
                dfs(board,nx,ny);
            }
        }
        else                        //cnt>0:规则3
            board[x][y]=cnt+'0';    //转换为数字字符
    }
};

