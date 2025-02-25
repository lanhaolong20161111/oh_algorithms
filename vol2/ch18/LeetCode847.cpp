struct QNode {                          //���н������
  int vno;                              //������
  int state;                       //��Ӧ��״̬
};
class Solution {
public:
  int shortestPathLength(vector<vector<int>>& graph) {
    int n=graph.size();                   //�������
      int endstate=(1<<n)-1;              //Ŀ��״̬
      int visited[n][1<<n];
      memset(visited,0,sizeof(visited));
      QNode e,e1;
      queue<QNode> qu;
      for(int i=0;i<n;i++) {        //���ж��㼰���ʼ״̬����
        e.vno=i;
        e.state=addj(0,i);          //��Ӷ���i
        qu.push(e);
        visited[i][e.state]=1;
    }
      int bestd=0;							//��Ŵ�
      while(!qu.empty()) {
        int cnt=qu.size();              //�����Ԫ�ظ���
        for(int i=0;i<cnt;i++) {        //����ò������Ԫ��
          e=qu.front(); qu.pop();       //����(u,state)
          int u=e.vno;
          int state=e.state;
          if (state==endstate)            //��һ���ҵ�Ŀ��״̬�򷵻�
            return bestd;
          for(int v:graph[u]) {           //��u���������ڶ���v
            e1.vno=v;
            e1.state=addj(state,v);   //��Ӷ���v
            if(visited[v][e1.state]==1) //�Ѿ�����������
              continue;
            qu.push(e1);
            visited[v][e1.state]=1;
          }
      }
        bestd++;                          //����һ�㣬·����������1
    }
      return -1;                            //û���ҵ�Ŀ��״̬����-1
  }
  int addj(int state,int j) {               //��state��Ӷ���j
    return state | (1<<j);
  }
};

