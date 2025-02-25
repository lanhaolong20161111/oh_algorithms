struct QNode {                                      //���ȶ��н������
    int r,c;                                        //��ǰλ��
    int f,g,h;                                      //����ʽ����ֵ
    bool operator<(const QNode &s) const  {         //����<��ϵ����
          return f>s.f;                             //fԽСԽ���ȳ���
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
        vector<vector<int>> minf(m,vector<int>(n,INF));
        minf[start[0]][start[1]]=0;
        e.r=start[0];e.c=start[1];
        e.g=0;e.h=geth(start[0],start[1],dest[0],dest[1]);
        e.f=e.g+e.h;
        pqu.push(e);
        minf[start[0]][start[1]]=0;
        while(!pqu.empty()) {
            e=pqu.top(); pqu.pop();
            int r=e.r,c=e.c;
            if(r==dest[0] && c==dest[1])    //�ҵ�Ŀ��ֱ�ӷ���
                return e.g;
            for(int di=0;di<4;di++) {
                int nr=r,nc=c;
                int delta=0;
                while(nr+dr[di]>=0 && nr+dr[di]<m && nc+dc[di]>=0 && nc+dc[di]<n
                        && maze[nr+dr[di]][nc+dc[di]]==0) {   //��di�������(nr,nc)
                    nr+=dr[di];
                    nc+=dc[di];
                    delta++;                            //�ߵĿյ���
                }
                e1.r=nr;e1.c=nc;
                e1.g=e.g+delta;
                e1.h=geth(nr,nc,dest[0],dest[1]);
                e1.f=e1.g+e1.h;
                if(e1.f<minf[nr][nc]) {
                    minf[nr][nc]=e1.f;
                    pqu.push(e1);
                }
            }
        }
        return -1;
    }
    double geth(int x,int y,int gx,int gy) { //��������ʽ����ֵ
        return abs(gx-x)+abs(gy-y);
    }
};

