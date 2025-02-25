struct Edge {                                     //出边类
    int vno;                                      //邻接点
    int wt;                                       //边的权
    Edge(int v,int w):vno(v),wt(w) {}
};
class Solution {
    const int INF=0x3f3f3f3f;                                   //表示∞
public:
    int findCheapestPrice(int n,vector<vector<int>>& flights,int src,int dst,int k) {
        vector<vector<Edge>> adj(n);            //邻接表
        for(int i=0;i<flights.size();i++) {   //遍历flights建立邻接表
            int a=flights[i][0];
            int b=flights[i][1];
            int w=flights[i][2];         //<a,b>:w
            adj[a].push_back(Edge(b,w));
        }
        vector<int> dist(n,INF);
        dist[src]=0;
        queue<pair<int,int>> qu;		//队列元素类型为(vno,length)
        qu.push(pair<int,int>(src,0));
        k+=1;
        while(k-- && !qu.empty()) {
            int cnt=qu.size();
            for(int i=0;i<cnt;i++) {
                pair<int,int> e=qu.front();qu.pop();
                int u=e.first,length=e.second;
                for(auto edj:adj[u]) {
                    int v=edj.vno,w=edj.wt;
                    if(length+w<dist[v]) {      //边松驰
                        dist[v]=length+w;
                        qu.push(pair<int,int>(v,dist[v]));
                    }
                }
            }
        }
        if(dist[dst]==INF) return -1;
        return dist[dst];
    }
};

