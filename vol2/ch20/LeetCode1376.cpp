struct QNode {              //�����н������
  int vno;                  //Ա��ID
  int length;               //���ﵱǰԱ����ʱ��
};
class Solution {
public:
      int numOfMinutes(int n,int headID,vector<int>& manager,vector<int>& informTime) {
        vector<vector<int>> adj(n);     //ͼ���ڽӱ�
        for (int i=0;i<n;i++) {
          if(manager[i]!=-1)  //i�����ܸ����ˣ���ֱ��������Ϊmanager[i]
            adj[manager[i]].push_back(i);
        }
        QNode e,e1;
        queue<QNode> qu;
        e.vno=headID;
        e.length=informTime[headID];
        qu.push(e);
        int ans=0;                                //��Ŵ�
        while (!qu.empty()) {
          e=qu.front(); qu.pop();
          int u=e.vno,length=e.length;
          for (int v:adj[u]) {    //�ҵ�u������v
            e1.vno=v;
            e1.length=length+informTime[v];
            if(adj[e1.vno].size()==0)          //v��Ҷ�ӽ��
              ans=max(ans,e1.length);   //����ʱ������ֵ
            else
              qu.push(e1);
          }
        }
        return ans;
   }
};

