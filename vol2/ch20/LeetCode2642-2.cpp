struct Edge {                                     //������
    int vno;                                      //�ڽӵ�
    int wt;                                       //�ߵ�Ȩ
    Edge(int v,int w):vno(v),wt(w) {}
};
struct QNode {                  //���ȶ���Ԫ������
    int vno;                    //������
    int length;                 //·������
    bool operator<(const QNode& b) const {
        return length>b.length;     //lengthԽСԽ���ȳ���
    }
};

class Graph {
    const int INF=0x3f3f3f3f;
    vector<vector<Edge>> adj;     //ͼ���ڽӱ�
public:
    Graph(int n,vector<vector<int>>& edges) {
        adj=vector<vector<Edge>>(n);
        for(int i=0;i<edges.size();i++)        //����edges�����ڽӱ�
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
        priority_queue<QNode> qu;   //�������qu
        QNode e,e1;
        e.vno=node1;e.length=0;
        qu.push(e);        //Դ��Ԫ�ؽ���
        vector<int> dist(n,INF);
        dist[node1]=0;
        int ans=INF;
        while(!qu.empty()) {
            e=qu.top();qu.pop();      //����Ԫ��e
            int u=e.vno,length=e.length;
            if(u==node2) return length;   //�ҵ�Ŀ��
            for(auto edj:adj[u]) {
                int v=edj.vno,w=edj.wt;
                if(dist[u]+w<dist[v]) {      //��֧1���߳����ɳ�
                    dist[v]=dist[u]+w;
                    if(dist[v]<ans) {       //��֧2
                        e1.vno=v;e1.length=dist[v];
                        qu.push(e1);
                    }
                }
            }
        }
        return -1;
    }
};
