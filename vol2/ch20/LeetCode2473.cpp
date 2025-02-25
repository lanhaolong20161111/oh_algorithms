typedef long long LL;
struct Edge {                                     //������
    int vno;                                      //�ڽӵ�
    LL wt;                                       //�ߵ�Ȩ
    Edge(int v,LL w):vno(v),wt(w) {}
};
struct QNode {                  //���ȶ��н������
    int vno;                    //������
    int length;                 //·������
    bool operator<(const QNode& b) const {
        return length>b.length;     //lengthԽСԽ���ȳ���
    }
};
class Solution {
    const LL INF=0x3f3f3f3f3f3f3f3f;
public:
    vector<long long> minCost(int n,vector<vector<int>>&roads,vector<int>& appleCost,int k) {
        vector<vector<Edge>> adj(n+1);      //�ڽӱ�
        for(int i=0;i<roads.size();i++) {   //����road�����ڽӱ�
            int a=roads[i][0];
            int b=roads[i][1];
            LL w=(k+1)*roads[i][2];         //<a,b>:w
            adj[a].push_back(Edge(b,w));
            adj[b].push_back(Edge(a,w));
        }
        for(int i=1;i<=n;i++) {         //������Դ��ı�
            adj[0].push_back(Edge(i,appleCost[i-1]));
            adj[i].push_back(Edge(0,appleCost[i-1]));
        }
        vector<LL> dist(n+1,INF);
        priority_queue<QNode> pqu;          //С����
        QNode e,e1;
        dist[0]=0;
        e.vno=0; e.length=0;
        pqu.push(e);
        while(!pqu.empty()) {
            int u=pqu.top().vno;pqu.pop();  //���Ӷ���u
            for(auto edj:adj[u]) {
                int v=edj.vno;
                LL w=edj.wt;
                if(dist[v]>dist[u]+w) {     //���ɳ�
                    dist[v]=dist[u]+w;
                    e1.vno=v;
                    e1.length=dist[v];
                    pqu.push(e1);
                }
            }
        }
        vector<LL> ans(n);
        for(int i=1;i<=n;i++)
            ans[i-1]=dist[i];
        return ans;
    }
};

