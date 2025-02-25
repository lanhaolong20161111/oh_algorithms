struct Edge {                                     //出边类
    int vno;                                      //邻接点
    int wt;                                       //边的权
    Edge(int v,int w):vno(v),wt(w) {}
};
struct QNode {                  //优先队列结点类型
    int vno;                    //顶点编号
    int length;                 //路径长度
    bool operator<(const QNode& b) const {
        return length>b.length;     //length越小越优先出队
    }
};
class Solution {
    const int INF=0x3f3f3f3f;
public:
    int networkDelayTime(vector<vector<int>>& times,int n,int k) {
        vector<vector<Edge>> adj(n);              //邻接表
        for(int i=0;i<times.size();i++) {       //遍历times建立邻接表
            int a=times[i][0]-1;
            int b=times[i][1]-1;
            int w=times[i][2];                  //<a,b>:w
            adj[a].push_back(Edge(b,w));
        }
        int s=k-1;                      //源点为s
        vector<int> dist(n,INF);      //定义dist并初始化所有元素为INF
        dist[s]=0;
        QNode e,e1;
        priority_queue<QNode> pqu;        //定义一个小根堆pqu
        e.vno=s;e.length=0;
        pqu.push(e);              //源点元素进队
        while(!pqu.empty()) {                 //队列不空循环
            e=pqu.top(); pqu.pop();             //出队元素e
            int u=e.vno;
            for(auto edj:adj[u]) {
                int v=edj.vno;               //相邻顶点为v
                if(dist[u]+edj.wt<dist[v]) {     //边松驰:u到v有边且路径长度更短
                    dist[v]=dist[u]+edj.wt;
                    e1.vno=v;e1.length=dist[v];
                    pqu.push(e1);              //元素e1进队
                }
            }
        }
        int ans=dist[0];
        for(int i=1;i<n;i++) {
            if(dist[i]>ans) ans=dist[i];
        }
        if(ans==INF) return -1;
        else  return ans;
    }
};

