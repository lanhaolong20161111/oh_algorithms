struct Edge {                                     //出边类
    int vno;                                      //邻接点
    int wt;                                       //边的权
    Edge(int v,int w):vno(v),wt(w) {}
};
class Solution {
    const int INF=0x3f3f3f3f;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
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
        queue<int> qu;          //定义一个队列qu
        qu.push(s);              //源点进队
        while(!qu.empty()) {                    //队列不空循环
            int u=qu.front(); qu.pop();             //出队顶点u
            for(auto edj:adj[u]) {
                int v=edj.vno;               //相邻顶点为v
                int w=edj.wt;
                if(dist[u]+w<dist[v]) {     //边松驰:u到v有边且路径长度更短
                    dist[v]=dist[u]+w;
                    qu.push(v);              //顶点v进队
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

