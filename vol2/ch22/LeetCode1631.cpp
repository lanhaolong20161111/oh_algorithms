struct QNode {                    //���ȶ��н������
  int x,y;
  int length;
  bool operator<(const QNode& b) const {
    return length>b.length;         					//��·������lengthԽСԽ���ȳ���
  }
};
class Solution {
  int dx[4]={0,0,1,-1};                           //ˮƽ����ƫ����
  int dy[4]={1,-1,0,0};                           //��ֱ����ƫ����
  const int INF=0x3f3f3f3f;
public:
  int minimumEffortPath(vector<vector<int>>& heights) {
      int m=heights.size(),n=heights[0].size();
      vector<vector<int>> dist(m,vector<int>(n,INF));
      QNode e,e1;
      priority_queue<QNode> pqu;        //�������ȶ���
      e1.x=0; e1.y=0;               //(0,0)����
      e1.length=0;
      pqu.push(e1);
      dist[0][0]=0;
      while(!pqu.empty()) {
          e=pqu.top(); pqu.pop();
          int x=e.x, y=e.y;
          int length=e.length;
          if(x==m-1 && y==n-1)          //�ҵ��յ㷵��
            return e.length;
          for(int di=0;di<4;di++) {					//��չ
            int nx=x+dx[di]; int ny=y+dy[di];
            if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
            int curlen=max(length,abs(heights[nx][ny]-heights[x][y]));
            if(curlen<dist[nx][ny]) {   		//���ɳ�
            		dist[nx][ny]=curlen;
            		e1.x=nx; e1.y=ny; e1.length=curlen;
            		pqu.push(e1);
          }
        }
      }
      return -1;
  }
};

