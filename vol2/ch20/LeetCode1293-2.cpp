struct QNode {              //���н������
  int x,y;                                //λ��
  int nums;                               //�ϰ������
  int length;                             //·������
  bool operator<(const QNode& b) const {
        return length>b.length;     //lengthԽСԽ���ȳ���
  }
};
class Solution {
  const int INF=0x3f3f3f3f;
  int dx[4]={0,0,1,-1};                       //ˮƽ����ƫ����
  int dy[4]={1,-1,0,0};                       //��ֱ����ƫ����
public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int m=grid.size(),n=grid[0].size();       //������
    if (k>=m+n-2) return m+n-2;
    vector<vector<int>> cnt(m,vector<int>(n,INF));
    QNode e,e1;
    priority_queue<QNode> qu;
    e.x=0; e.y=0; e.length=0; e.nums=0;
    qu.push(e);
    cnt[0][0]=0;
    int ans=INF;
    while (!qu.empty()) {
      e=qu.top(); qu.pop();
      int x=e.x,y=e.y,length=e.length,nums=e.nums;
      if(x==m-1 && y==n-1)                //�ҵ�Ŀ��
        ans=min(ans,length);              //����С·��
      for(int di=0;di<4;di++) {           //��������
        int nx=x+dx[di],ny=y+dy[di];      //di��λλ��Ϊ(nx,ny)
        if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
        int nnums=nums+grid[nx][ny];      //��λ���������ϰ������
        if(nnums>k) continue;             //��֧1
        if(nnums>=cnt[nx][ny]) continue;  //��֧2
        if(length+1<ans) {                //��֧3
        cnt[nx][ny]=nnums;
        e1.x=nx; e1.y=ny;e1.length=length+1;e1.nums=cnt[nx][ny];
        qu.push(e1);
        }
      }
    }
    if(ans==INF) return -1;
    return ans;
  }
};

