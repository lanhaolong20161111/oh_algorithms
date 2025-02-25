class Solution {
    const int INF=0x3f3f3f3f;
    int m,n;
    vector<vector<int>> dist;
    int dr[4]={1, 0, 0, -1};                        //��ֱ����ƫ����
    int dc[4]={0, -1,1, 0};                         //ˮƽ����ƫ����
    int tr,tc;                                      //Ŀ��λ��
public:
    int shortestDistance(vector<vector<int>>&maze,vector<int>& start,vector<int>& dest) {
        m=maze.size(),n=maze[0].size();
        dist=vector<vector<int>>(m,vector<int>(n,INF));
        int sr=start[0],sc=start[1];
        tr=dest[0]; tc=dest[1];
        dist[sr][sc]=0;
        dfs(maze,sr,sc);
        return dist[tr][tc]==INF?-1:dist[tr][tc];
    }
    void dfs(vector<vector<int>>&maze,int r,int c) {		//�����㷨
        for (int di=0;di<4;di++) {
            int delta=0;
            int nr=r, nc=c;
            while(nr+dr[di]>=0 && nr+dr[di]<m 
                    && nc+dc[di]>=0 && nc+dc[di]<n
                    && maze[nr+dr[di]][nc+dc[di]]==0) {  //��di�������
                nr+=dr[di];
                nc+=dc[di];
                delta++;						//�ۼƱ��ι��������Ŀյ���
            }
            if (dist[r][c]+delta<dist[nr][nc]) {         //���ɳ�
                dist[nr][nc]=dist[r][c]+delta;
                dfs(maze,nr,nc);
            }
        }
    }
};

