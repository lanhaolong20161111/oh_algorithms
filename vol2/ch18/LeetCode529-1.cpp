class Solution {
public:
    int dx[8]={0,1,0,-1,1,1,-1,-1};  //ˮƽ����ƫ����
    int dy[8]={1,0,-1,0,1,-1,1,-1};  //��ֱ����ƫ����
    int m,n;
   vector<vector<char>> updateBoard(vector<vector<char>>& board,vector<int>&click) {
        m=board.size();n=board[0].size();
        int x=click[0],y=click[1];
        if (board[x][y]=='M')       //����1
            board[x][y]='X';
        else
            dfs(board,x,y);
        return board;
    }
    int Count(vector<vector<char>>& board,int x,int y) {        //��(x,y)���ڵ�'M'����
        int nx,ny,cnt=0;
            for(int di=0;di<8;di++) {                       //����8����λ
                nx=x+dx[di];
                ny=y+dy[di];
                if(nx<0 || nx>=m || ny<0 || ny>=n)      //���Գ����λ��
                    continue;
                if(board[nx][ny]=='M') cnt++;           //�����ڵ��׸���cnt
            }
        return cnt;
    }
    void dfs(vector<vector<char>>& board,int x,int y) {     //�����������
        int cnt=Count(board,x,y);
        if(cnt==0) {                                //cnt=0:����2
            board[x][y]='B';
            for (int di=0;di<8;di++) {
                int nx=x+dx[di];
                int ny=y+dy[di];
                if(nx<0 || nx>=m || ny<0 || ny>=n)      //���Գ����λ��
                    continue;
                if(board[nx][ny]=='B')    //Ϊ'B'ʱ������Ϊ'B'֮ǰ�������ʱ���Ѿ�����չ����
                    continue;
                dfs(board,nx,ny);
            }
        }
        else                        //cnt>0:����3
            board[x][y]=cnt+'0';    //ת��Ϊ�����ַ�
    }
};

