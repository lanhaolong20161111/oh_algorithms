struct QNode {              //队列结点类型
  int x,y;                                //位置
  int nums;                               //障碍物个数
  int length;                             //路径长度
  bool operator<(const QNode& b) const {
        return length>b.length;     //length越小越优先出队
  }
};
class Solution {
  const int INF=0x3f3f3f3f;
  int dx[4]={0,0,1,-1};                       //水平方向偏移量
  int dy[4]={1,-1,0,0};                       //垂直方向偏移量
public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int m=grid.size(),n=grid[0].size();       //行列数
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
      if(x==m-1 && y==n-1)                //找到目标
        ans=min(ans,length);              //求最小路径
      for(int di=0;di<4;di++) {           //四周搜索
        int nx=x+dx[di],ny=y+dy[di];      //di方位位置为(nx,ny)
        if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
        int nnums=nums+grid[nx][ny];      //新位置遇到的障碍物个数
        if(nnums>k) continue;             //剪支1
        if(nnums>=cnt[nx][ny]) continue;  //剪支2
        if(length+1<ans) {                //剪支3
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

