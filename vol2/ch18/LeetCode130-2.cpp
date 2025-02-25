class Solution {
    int dx[4]={0,0,1,-1};                       //ˮƽ����ƫ����
    int dy[4]={1,-1,0,0};                       //��ֱ����ƫ����
    int m,n;
    queue<pair<int,int>> qu;                //����һ������qu
public:
    void solve(vector<vector<char>>& board) { 
        m=board.size();                                     //����
        n=board[0].size();                          //����
        for (int i=0;i<m;i++) {                     //��������һȦ��'O'
            for (int j=0;j<n;j++) {
                if ((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O') {
                    board[i][j]='$';        //�������ַ�'$'�滻
                    qu.push(pair<int,int>(i,j));   //��������һȦ������'O'����
                }
             }
        }
        bfs(board);
        for (int i=0;i<m;i++) {                             //�滻
            for (int j=0;j<n;j++) {
                if (board[i][j]=='$')
                    board[i][j]='O';
                else if (board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
    void bfs(vector<vector<char>>& board) {     //����������ȱ���
        while(!qu.empty()) {                              //�Ӳ���ʱѭ��
            auto e=qu.front(); qu.pop();        //����Ԫ��e
            int i=e.first,j=e.second;
            for (int di=0;di<4;di++) {
                int x=i+dx[di];                //���di��λ������λ��(x,y)
                int y=j+dy[di];
                if (x<0 || x>=m || y<0 || y>=n || board[x][y]!='O') 
                    continue;                      //������߲���'O'ʱ����
                board[x][y]='$';
                qu.push(pair<int,int>(x,y));            //(x,y)����
            }
        }
    }
};

