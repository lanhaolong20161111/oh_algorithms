class Solution {
    int dx[4]={0,0,1,-1};                        //ˮƽ����ƫ����
    int dy[4]={1,-1,0,0};                        //��ֱ����ƫ����
    int m,n;
public:
    void solve(vector<vector<char>>& board) {
        m=board.size();                     //����
        n=board[0].size();                  //����
        for (int i=0;i<m;i++) {                  //��������һȦ�ҵ�һ��'O'
            for (int j=0;j<n;j++) {
                if ((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O') 
                    dfs(board,i,j);
            }
        }
        for (int i=0;i<m;i++) {                     //�滻
            for (int j=0;j<n;j++) {
                if (board[i][j]=='$')
                    board[i][j]='O';
                else if (board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
    void dfs(vector<vector<char>>& board,int i,int j) {     //(i,j)λ�ó���������ȱ���
        board[i][j]='$';
        for (int di=0;di<4;di++) {
            int x=i+dx[di];
            int y=j+dy[di];
            if (x<0 || x>=m || y<0 || y>=n || board[x][y]!='O') 
                continue;                                   //������߲���'O'ʱ����
            dfs(board,x,y);
        }
    }
};

