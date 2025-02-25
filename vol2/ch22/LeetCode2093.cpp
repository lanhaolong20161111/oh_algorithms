struct Edge {                                     //出边类
    int vno;                                      //邻接点
    int wt;                                       //边的权
    Edge(int v,int w):vno(v),wt(w) {}
};
struct QNode {                  //优先队列结点类型
    int vno;                    //顶点编号
    int length;                 //路径长度
    int disc;                   //打折次数
    bool operator<(const QNode& b) const {
        return length>b.length;     //length越小越优先出队
    }
};
class Solution {
    const int INF=0x3f3f3f3f;
public:
    int minimumCost(int n,vector<vector<int>>& highways,int discounts) {
        vector<vector<Edge>> adj(n);      //邻接表
        for(int i=0;i<highways.size();i++) {   //遍历highways建立邻接表
            int a=highways[i][0];
            int b=highways[i][1];
            int w=highways[i][2];         //<a,b>:w
            adj[a].push_back(Edge(b,w));
            adj[b].push_back(Edge(a,w));
        }
        priority_queue<QNode> pqu;  //定义小根堆pqu,元素为[花费,vno,打折次数]
        QNode e,e1,e2;
        e.vno=0;e.length=0;e.disc=0;
        pqu.push(e);               					//源点元素进队
        vector<vector<int>> dist(n,vector<int>(discounts+1,INF));
        while(!pqu.empty()) {
            e=pqu.top();pqu.pop();            //出队结点e
            int cost=e.length,u=e.vno,disc=e.disc;
            if(disc>discounts) continue;      //剪支：超过折扣次数时跳过
            if(u==n-1) return cost;				//找到目标
            if(cost<dist[u][disc]) {
                dist[u][disc]=cost;
                for(auto edj:adj[u]) {
                    int v=edj.vno,w=edj.wt;				//不打折扣
                    e1.vno=v;e1.length=cost+w;e1.disc=disc;
                    pqu.push(e1);
                    e2.vno=v;e2.length=cost+w/2;e2.disc=disc+1;
                    pqu.push(e2);							//打折扣
                }
            }
        }
        return -1;
    }
};

