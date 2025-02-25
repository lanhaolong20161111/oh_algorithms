struct QNode {                          //队列结点类型
  int vno;                              //顶点编号
  int state;                       //对应的状态
};
class Solution {
public:
  int shortestPathLength(vector<vector<int>>& graph) {
    int n=graph.size();                   //顶点个数
      int endstate=(1<<n)-1;              //目标状态
      int visited[n][1<<n];
      memset(visited,0,sizeof(visited));
      QNode e,e1;
      queue<QNode> qu;
      for(int i=0;i<n;i++) {        //所有顶点及其初始状态进队
        e.vno=i;
        e.state=addj(0,i);          //添加顶点i
        qu.push(e);
        visited[i][e.state]=1;
    }
      int bestd=0;							//存放答案
      while(!qu.empty()) {
        int cnt=qu.size();              //求队中元素个数
        for(int i=0;i<cnt;i++) {        //处理该层的所有元素
          e=qu.front(); qu.pop();       //出队(u,state)
          int u=e.vno;
          int state=e.state;
          if (state==endstate)            //第一次找到目标状态则返回
            return bestd;
          for(int v:graph[u]) {           //找u的所有相邻顶点v
            e1.vno=v;
            e1.state=addj(state,v);   //添加顶点v
            if(visited[v][e1.state]==1) //已经访问则跳过
              continue;
            qu.push(e1);
            visited[v][e1.state]=1;
          }
      }
        bestd++;                          //搜索一层，路径长度增加1
    }
      return -1;                            //没有找到目标状态返回-1
  }
  int addj(int state,int j) {               //在state添加顶点j
    return state | (1<<j);
  }
};

