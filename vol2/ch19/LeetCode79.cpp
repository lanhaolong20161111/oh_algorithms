class Solution {
    int dr[4]={0,0,1,-1};                    //���з����ƫ����
    int dc[4]={1,-1,0,0};                       //���з����ƫ����
    vector<vector<int>> visited;                  //���ʱ������
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
                    dfs(board,word,r,c,1);						//i��1��ʼ
                    if(ans) return true;
                    visited[r][c]=0;
                }
            }
        }
        return false;
    }
    void dfs(vector<vector<char>>&board,string&word,int r,int c,int i) {		//�����㷨
        if(i>=word.size())
            ans=true;
        else if(!ans) {
            for(int di=0;di<4;di++) {			//������̽
                int nr=r+dr[di];    //��di��λ������λ��[nr,nc]
                int nc=c+dc[di];
                if(nr<0 || nr>=board.size() || nc<0 || nc>=board[0].size())
                    continue;       //������Ч��[nr,nc]
                if(visited[nr][nc]==1)
                    continue;       //�����Ѿ����ʵ�[nr,nc]
                if(board[nr][nc]==word[i]) {
                    visited[nr][nc]=1;
                    dfs(board,word,nr,nc,i+1);
                    visited[nr][nc]=0;
                }
            }
        }
    }
};

