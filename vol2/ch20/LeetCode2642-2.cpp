struct Edge {                                     //出边类
    int vno;                                      //邻接点
    int wt;                                       //边的权
    Edge(int v,int w):vno(v),wt(w) {}
};
struct QNode {                  //优先队列元素类型
    int vno;                    //顶点编号
    int length;                 //路径长度
    bool operator<(const QNode& b) const {
        return length>b.length;     //length越小越优先出队
    }
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
        priority_queue<QNode> qu;   //定义队列qu
        QNode e,e1;
        e.vno=node1;e.length=0;
        qu.push(e);        //源点元素进队
        vector<int> dist(n,INF);
        dist[node1]=0;
        int ans=INF;
        while(!qu.empty()) {
            e=qu.top();qu.pop();      //出队元素e
            int u=e.vno,length=e.length;
            if(u==node2) return length;   //找到目标
            for(auto edj:adj[u]) {
                int v=edj.vno,w=edj.wt;
                if(dist[u]+w<dist[v]) {      //剪支1：边长度松驰
                    dist[v]=dist[u]+w;
                    if(dist[v]<ans) {       //剪支2
                        e1.vno=v;e1.length=dist[v];
                        qu.push(e1);
                    }
                }
            }
        }
        return -1;
    }
};
