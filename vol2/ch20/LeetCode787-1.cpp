struct Edge {                                     //出边类
    int vno;                                      //邻接点
    int wt;                                       //边的权
    Edge(int v,int w):vno(v),wt(w) {}
};
struct QNode {                  //队列元素类型
    int vno;                    	//顶点编号
    int length;                 	//路径长度
    int nums;                   	//中转的城市数
};
class Solution {
    const int INF=0x3f3f3f3f;                                   //表示∞
public:
    int findCheapestPrice(int n,vector<vector<int>>&flights,int src,int dst,int k) {
        vector<vector<Edge>> adj(n);            //邻接表
        for(int i=0;i<flights.size();i++) {   //遍历flights建立邻接表
            int a=flights[i][0];
            int b=flights[i][1];
            int w=flights[i][2];         //<a,b>:w
            adj[a].push_back(Edge(b,w));
        }
        queue<QNode> qu;               //定义队列qu
        QNode e,e1;
        e.vno=src;e.length=0;e.nums=0;
        qu.push(e);                     //源点元素进队
        vector<int> dist(n,INF);
        dist[src]=0;
        int ans=INF;
        while(!qu.empty()) {
            e=qu.front();qu.pop();      //出队元素e
            int u=e.vno,length=e.length,nums=e.nums;
            if(u==dst) ans=min(ans,length); 		//找到目标
            for(auto edj:adj[u]) {
                int v=edj.vno,w=edj.wt;
                e1.vno=v;e1.nums=nums+1;
                if(e1.nums>k+1) continue;       //剪支1
                if(length+w<dist[v]) {          //剪支2：边松驰
                    dist[v]=length+w;
                    if(dist[v]<ans) {           //剪支3
                        e1.length=dist[v];
                        qu.push(e1);
                    }
                }
            }
        }
        if(ans==INF) return -1;
        return ans;
    }
};

