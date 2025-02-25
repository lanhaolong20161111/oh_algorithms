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
    int dr[4]={0,0,-1,1};            //ˮƽ����ƫ����
    int dc[4]={-1,1,0,0};            //��ֱ����ƫ����
public:
    int shortestDistance(vector<vector<int>>&maze,vector<int>& start,vector<int>& dest) {
        int m=maze.size(),n=maze[0].size();
        priority_queue<QNode> pqu;
        QNode e,e1;
        vector<vector<int>> dist(m,vector<int>(n,INF));
        vector<vector<bool>> S(m,vector<bool>(n,false));
        dist[start[0]][start[1]]=0;
        S[start[0]][start[1]]=true;
        e=QNode(start[0],start[1],0);
        pqu.push(e);
        while(!pqu.empty()) {
            e=pqu.top(); pqu.pop();
            int r=e.r,c=e.c,steps=e.steps;
            S[r][c]=true;                //��(r,c)��ӵ�S������
            if(r==dest[0] && c==dest[1])    //�ҵ�Ŀ��ֱ�ӷ���
                return dist[r][c];
            for(int di=0;di<4;di++) {
                int nr=r,nc=c;
                int delta=0;
                while(nr+dr[di]>=0 && nr+dr[di]<m && nc+dc[di]>=0 && nc+dc[di]<n
                        && maze[nr+dr[di]][nc+dc[di]]==0) {  //��di�������(nr,nc)
                    nr+=dr[di];
                    nc+=dc[di];
                    delta++;                    //�ߵĲ�������
                }
                if(S[nr][nc]) continue;      //���޸Ĳ���S�е�λ��
                if(dist[r][c]+delta<dist[nr][nc]) {     //���ɳ�
                    dist[nr][nc]=dist[r][c]+delta;
                    e1=QNode(nr,nc,dist[nr][nc]);
                    pqu.push(e1);
                }
            }
        }
        return -1;
    }
};

