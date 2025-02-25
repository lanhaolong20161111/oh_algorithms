struct QNode {                                                //优先队列结点类型
  int x,y;                                                        //0的位置
      string grid;                                                  //棋盘字符串
      int f,g,h;                                                      //启发式函数值
    bool operator<(const QNode &s) const  {         //重载<关系函数
          return f>s.f;                                           //f越小越优先出队
      }
};
class Solution {
  int dx[4]={0,0,1,-1};                                     //水平方向偏移量
      int dy[4]={1,-1,0,0};                                     //垂直方向偏移量
      string goal="123450";
public:
      int slidingPuzzle(vector<vector<int>>& board) {
          int m=2,n=3;
          string s; 
          int x,y;
          for (int i=0;i<m;i++) {                                 //将board转换为s并找到0的位置
              for (int j=0;j<n;j++) {
                  s.push_back(board[i][j]+'0');
                  if (board[i][j]==0) x=i,y=j;
              }
          }
          if (s==goal) return 0;
          unordered_set<string> visited;
          priority_queue<QNode> pqu;
          QNode e,e1;
          e.x=x; e.y=y; e.grid=s;
          e.g=0; e.h=geth(s);               //或者e.h=0
          e.f=e.g+e.h;
          pqu.push(e);                                            //初始状态进队
          visited.insert(e.grid);                                 //标记初始状态已访问
          while (!pqu.empty()) {
            e=pqu.top(); pqu.pop();
              x=e.x;y=e.y;s=e.grid;
              int p0=x*n+y;
              for (int di=0;di<4;di++) {
                int nx=x+dx[di],ny=y+dy[di];
                  if (nx<0 || nx>=m || ny<0 || ny>=n) continue;
                    int p1=nx*n+ny;
                    swap(s[p0],s[p1]);					//移动一次
                    if (goal==s) return e.g+1;		//找到目标状态
                    if (!visited.count(s)) {
                        visited.insert(s);
                        e1.x=nx; e1.y=ny; e1.grid=s;
                        e1.g=e.g+1;
                        e1.h=geth(s);
                        e1.f=e1.g+e1.h;
                        pqu.push(e1);
                    }
                    swap(s[p0],s[p1]);                    //恢复s
                  }
          }
          return -1;                                            //没有找到返回false
      }
      int geth(string &s) {                                   //计算启发式函数值
          int h=0;
          for(int i=0;i<6;i++) {
              if(s[i]!='0' && goal[i]!=s[i]) h++;
          }
          return h;
      }
};

