struct QNode {                  //���ȶ��н������
    int x,y;                    //λ��
    int length;                 //·������
    bool operator<(const QNode& b) const {
        return length<b.length;     //lengthԽ��Խ���ȳ���
    }
};
class Solution {
    int dx[4]={0,0,1,-1};                       //ˮƽ����ƫ����
    int dy[4]={1,-1,0,0};                        //��ֱ����ƫ����
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,-1));
        priority_queue<QNode> pqu;
        QNode e,e1;
        e.x=0;e.y=0;e.length=grid[0][0];
        pqu.push(e);
        dist[0][0]=grid[0][0];
        while(!pqu.empty()) {
            e=pqu.top();pqu.pop();      //����Ԫ��e
            int x=e.x,y=e.y,length=e.length;
            if(x==m-1 && y==n-1) return length;		//�ҵ�Ŀ��
            for(int di=0;di<4;di++) {						//��չ
                int nx=x+dx[di];
                int ny=y+dy[di];
                if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
                int curlen=min(dist[x][y],grid[nx][ny]);
                if(curlen>dist[nx][ny]) {				//���ɳ�
                    dist[nx][ny]=curlen;
                    e1.x=nx;e1.y=ny;e1.length=dist[nx][ny];
                    pqu.push(e1);
                }
            }
        }
        return -1;
    }
};

