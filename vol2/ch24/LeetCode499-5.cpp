struct QNode {                  //���ȶ����н������
    int r,c;
    int steps;
    QNode() {}
    QNode(int r1,int c1,int s1):r(r1),c(c1),steps(s1) {}
    bool operator<(const QNode&s) const {
        return steps>s.steps;         //��stepsԽСԽ���ȳ���
    }
};
class Solution {
    const int INF=0x3f3f3f3f;
    int dr[4]={1,0,0,-1};                //��ֱ����ƫ����
    int dc[4]={0,-1,1,0};                 //ˮƽ����ƫ����
    vector<string> dirstr={"d","l","r","u"};    //��λ���ֵ�����С
public:
string findShortestWay(vector<vector<int>>&maze,vector<int>&ball,vector<int>&hole) {
        int m=maze.size(),n=maze[0].size();
        priority_queue<QNode> pqu;
        QNode e,e1;
        vector<vector<int>> dist(m,vector<int>(n,INF));
        vector<vector<string>> path(m,vector<string>(n,""));
        vector<vector<bool>> S(m,vector<bool>(n,false));
        dist[ball[0]][ball[1]]=0;
        S[ball[0]][ball[1]]=true;
        e=QNode(ball[0],ball[1],0);
        pqu.push(e);
        while(!pqu.empty()) {
            e=pqu.top(); pqu.pop();
            int r=e.r,c=e.c;
            S[r][c]=true;                //��(r,c)��ӵ�S������
            if(r==hole[0] && c==hole[1])    //һ���ҵ�Ŀ�ĵ��򷵻�
                return path[r][c];
            for(int di=0;di<4;di++) {
                int nr=r,nc=c;
                int delta=0;
                while(nr+dr[di]>=0 && nr+dr[di]<m && nc+dc[di]>=0 && nc+dc[di]<n
                        && maze[nr+dr[di]][nc+dc[di]]==0)   //��di�������(nr,nc)
                {
                    nr+=dr[di];
                    nc+=dc[di];
                    delta++;                    //�ߵĲ�������
                    if(nr==hole[0] && nc==hole[1]) 
                        break;                      //�ҵ���ʱ������Ϊͣ����
                }
                if(S[nr][nc]) continue;                 //���޸Ĳ���S�е�λ��
                int curdist=dist[r][c]+delta;
                string curpath=path[r][c]+dirstr[di];
                if (curdist<dist[nr][nc]) {          //�Ƚ������·��
                    dist[nr][nc]=curdist;
                    path[nr][nc]=curpath;
                    pqu.push(QNode(nr,nc,dist[nr][nc]));
                }
                else if (curdist==dist[nr][nc]) {       //��ͬ����ʱ
                    if(curpath<path[nr][nc]) {
                        path[nr][nc]=curpath;
                        pqu.push(QNode(nr,nc,dist[nr][nc]));
                    }
                }
            }
        }
        return "impossible";
    }
};

