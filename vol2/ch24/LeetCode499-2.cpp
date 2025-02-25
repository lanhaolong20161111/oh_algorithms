class Solution {
    const int INF=0x3f3f3f3f;
    int dr[4]={1, 0, 0, -1};                //��ֱ����ƫ����
    int dc[4]={0, -1,1, 0};                 //ˮƽ����ƫ����
    vector<string> dirstr={"d","l","r","u"};    //��λ���ֵ�����С
public:
string findShortestWay(vector<vector<int>>&maze,vector<int>&ball,vector<int>&hole) {
        int m=maze.size(),n=maze[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INF));
        vector<vector<string>> path(m,vector<string>(n,""));
        queue<pair<int,int>> qu;
        pair<int,int> e,e1;
        dist[ball[0]][ball[1]]=0;
        e=pair<int,int>(ball[0],ball[1]);
        qu.push(e);
        while(!qu.empty()) {
            e=qu.front(); qu.pop();
            int r=e.first,c=e.second;
            for(int di=0;di<4;di++) {
                int nr=r,nc=c;
                int delta=0;
                while(nr+dr[di]>=0 && nr+dr[di]<m && nc+dc[di]>=0 
                    && nc+dc[di]<n && maze[nr+dr[di]][nc+dc[di]]==0) {
                    nr+=dr[di];
                    nc+=dc[di];
                    delta++;                        //�ߵĲ�������
                    if(nr==hole[0] && nc==hole[1]) 
                        break;                  //�ҵ���ʱ������Ϊͣ����
                }
                int curdist=dist[r][c]+delta;
                string curpath=path[r][c]+dirstr[di];
                if (curdist<dist[nr][nc]) {          //�Ƚ������·��
                    dist[nr][nc]=curdist;
                    path[nr][nc]=curpath;
                    e1=pair<int,int>(nr,nc);
                    qu.push(e1);
                }
                else if (curdist==dist[nr][nc]) {   //��ͬ����ʱ
                    if(curpath<path[nr][nc]) {
                        path[nr][nc]=curpath;
                        e1=pair<int,int>(nr,nc);
                        qu.push(e1);
                    }
                }
            }
        }
        if(dist[hole[0]][hole[1]]==INF) return "impossible";
        else return path[hole[0]][hole[1]];
    }
};

