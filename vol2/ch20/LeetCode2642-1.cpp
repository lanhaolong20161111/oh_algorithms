struct Edge {                                     //出边类
    int vno;                                      //邻接点
    int wt;                                       //边的权
    Edge(int v,int w):vno(v),wt(w) {}
};
class Graph {
    const int INF=0x3f3f3f3f;
    vector<vector<Edge>> adj;     //图的邻接表
public:
    Graph(int n,vector<vector<int>>& edges) {
        adj=vector<vector<Edge>>(n);
        for(int i=0;i<edges.size();i++)        //遍历edges建立邻接表
            addEdge(edges[i]); 
    }    
    void addEdge(vector<int> edge) {
        int a=edge[0];
        int b=edge[1];
        int w=edge[2];                  //<a,b>:w
        adj[a].push_back(Edge(b,w));
    }
    
    int shortestPath(int node1,int node2) {
        int n=adj.size();
        queue<int> qu;   //定义队列qu,元素为(vno)
        qu.push(node1);        //源点元素进队
        vector<int> dist(n,INF);
        dist[node1]=0;
        int ans=INF;
        while(!qu.empty()) {
            int u=qu.front();qu.pop();      //出队顶点u
            if(u==node2) ans=min(ans,dist[u]);   //找到目标
            for(auto edj:adj[u]) {
                int v=edj.vno,w=edj.wt;
                if(dist[u]+w<dist[v]) {      //剪支1：边长度松驰
                    dist[v]=dist[u]+w;
                    if(dist[v]<ans)           //剪支2          
                        qu.push(v);
                }
            }
        }
        if(ans==INF) return -1;
        return ans;
    }
};

