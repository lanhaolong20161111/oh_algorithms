class Solution {
    const int INF=0x3f3f3f3f;
    vector<vector<int>> adj;
public:
    int findShortestCycle(int n,vector<vector<int>>& edges) {
        adj=vector<vector<int>>(n);
        for(auto e:edges) {             //创建邻接表adj
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans=INF;
        for (int u=0;u<n;u++) {
            for (int v:adj[u]) {
                ans=min(ans,bfs(n,u,v)+1);
            }
        }
        return ans==INF?-1:ans;
    }
    int bfs(int n,int u,int v) {
        vector<int> dist(n,INF);
        queue<int> qu;
        qu.push(u);
        dist[u]=0;
        while (!qu.empty()) {
            int i=qu.front(); qu.pop();
            for (int j:adj[i]) {
                if (dist[j]==INF) {
                    if (i==u && j==v) continue;
                    qu.push(j);
                    dist[j]=dist[i]+1;
                }
            }
        }
        return dist[v];
    }
};

