typedef long long LL;
struct Edge {                                     //出边类
    int vno;                                      //邻接点
    LL wt;                                       //边的权
    Edge(int v,LL w):vno(v),wt(w) {}
};
struct QNode {                  //优先队列结点类型
    int vno;                    //顶点编号
    int length;                 //路径长度
    bool operator<(const QNode& b) const {
        return length>b.length;     //length越小越优先出队
    }
};
class Solution {
    const LL INF=0x3f3f3f3f3f3f3f3f;
public:
    vector<long long> minCost(int n,vector<vector<int>>&roads,vector<int>& appleCost,int k) {
        vector<vector<Edge>> adj(n+1);      //邻接表
        for(int i=0;i<roads.size();i++) {   //遍历road建立邻接表
            int a=roads[i][0];
            int b=roads[i][1];
            LL w=(k+1)*roads[i][2];         //<a,b>:w
            adj[a].push_back(Edge(b,w));
            adj[b].push_back(Edge(a,w));
        }
        for(int i=1;i<=n;i++) {         //建超级源点的边
            adj[0].push_back(Edge(i,appleCost[i-1]));
            adj[i].push_back(Edge(0,appleCost[i-1]));
        }
        vector<LL> dist(n+1,INF);
        priority_queue<QNode> pqu;          //小根堆
        QNode e,e1;
        dist[0]=0;
        e.vno=0; e.length=0;
        pqu.push(e);
        while(!pqu.empty()) {
            int u=pqu.top().vno;pqu.pop();  //出队顶点u
            for(auto edj:adj[u]) {
                int v=edj.vno;
                LL w=edj.wt;
                if(dist[v]>dist[u]+w) {     //边松驰
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

