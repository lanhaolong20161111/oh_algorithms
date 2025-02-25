class Solution {
    const int INF=0x3f3f3f3f;
    int dr[4]={0,0,-1,1};            //ˮƽ����ƫ����
    int dc[4]={-1,1,0,0};            //��ֱ����ƫ����
public:
    int shortestDistance(vector<vector<int>>&maze,vector<int>&start,vector<int>&dest) {
        int m=maze.size(),n=maze[0].size();
        queue<pair<int,int>> qu;
        pair<int,int> e,e1;
        vector<vector<int>> dist(m,vector<int>(n,INF));
        dist[start[0]][start[1]]=0;
        e=pair<int,int>(start[0],start[1]);
        qu.push(e);
        while(!qu.empty()) {
            e=qu.front(); qu.pop();
            int r=e.first,c=e.second;
            for(int di=0;di<4;di++) {           //��(r,c)��չ
                int nr=r, nc=c;
                int delta=0;
                while(nr+dr[di]>=0 && nr+dr[di]<m && nc+dc[di]>=0 && 
                    nc+dc[di]<n && maze[nr+dr[di]][nc+dc[di]]==0)  {
                    nr+=dr[di];nc+=dc[di];      //di�������(nr,nc)
                    delta++;                            //�ߵĿյ���
                }
                if(dist[r][c]+delta<dist[nr][nc])  {   //���ɳ�
                    dist[nr][nc]=dist[r][c]+delta;
                    e1=pair<int,int>(nr,nc);
                    qu.push(e1);
                }
            }
        }
        if(dist[dest[0]][dest[1]]==INF) return -1;
        else return dist[dest[0]][dest[1]];
    }
};

