struct QNode {                    //优先队列结点类型
  int x,y;
  int length;
  bool operator<(const QNode& b) const {
    return length>b.length;         					//按路径长度length越小越优先出队
  }
};
class Solution {
  int dx[4]={0,0,1,-1};                           //水平方向偏移量
  int dy[4]={1,-1,0,0};                           //垂直方向偏移量
  const int INF=0x3f3f3f3f;
public:
  int minimumEffortPath(vector<vector<int>>& heights) {
      int m=heights.size(),n=heights[0].size();
      vector<vector<int>> dist(m,vector<int>(n,INF));
      QNode e,e1;
      priority_queue<QNode> pqu;        //定义优先队列
      e1.x=0; e1.y=0;               //(0,0)进队
      e1.length=0;
      pqu.push(e1);
      dist[0][0]=0;
      while(!pqu.empty()) {
          e=pqu.top(); pqu.pop();
          int x=e.x, y=e.y;
          int length=e.length;
          if(x==m-1 && y==n-1)          //找到终点返回
            return e.length;
          for(int di=0;di<4;di++) {					//扩展
            int nx=x+dx[di]; int ny=y+dy[di];
            if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
            int curlen=max(length,abs(heights[nx][ny]-heights[x][y]));
            if(curlen<dist[nx][ny]) {   		//边松驰
            		dist[nx][ny]=curlen;
            		e1.x=nx; e1.y=ny; e1.length=curlen;
            		pqu.push(e1);
          }
        }
      }
      return -1;
  }
};

