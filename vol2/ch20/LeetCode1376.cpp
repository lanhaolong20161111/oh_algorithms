struct QNode {              //队列中结点类型
  int vno;                  //员工ID
  int length;               //到达当前员工的时间
};
class Solution {
public:
      int numOfMinutes(int n,int headID,vector<int>& manager,vector<int>& informTime) {
        vector<vector<int>> adj(n);     //图的邻接表
        for (int i=0;i<n;i++) {
          if(manager[i]!=-1)  //i不是总负责人，其直属负责人为manager[i]
            adj[manager[i]].push_back(i);
        }
        QNode e,e1;
        queue<QNode> qu;
        e.vno=headID;
        e.length=informTime[headID];
        qu.push(e);
        int ans=0;                                //存放答案
        while (!qu.empty()) {
          e=qu.front(); qu.pop();
          int u=e.vno,length=e.length;
          for (int v:adj[u]) {    //找到u的下属v
            e1.vno=v;
            e1.length=length+informTime[v];
            if(adj[e1.vno].size()==0)          //v是叶子结点
              ans=max(ans,e1.length);   //求总时间的最大值
            else
              qu.push(e1);
          }
        }
        return ans;
   }
};

