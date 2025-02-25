class Solution {
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> path;
public:
    vector<int> distanceToCycle(int n,vector<vector<int>>& edges) {
        adj=vector<vector<int>>(n);
        for(auto e:edges) {						//创建邻接表adj
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> cycle=findCycle(n);			//找到环cycle
        vector<int> ans(n,n+1);
        for(int i:cycle) ans[i]=0;
        queue<int> qu;
        for(int i:cycle) qu.push(i);  				//将环cycle中全部顶点进队
        int dist=0;
        while(!qu.empty()) {        				//多起点非层次的广度优先搜索
            int cnt=qu.size();
            for(int i=0;i<cnt;i++) {
                int cur=qu.front(); qu.pop();
                for(int next:adj[cur]) {
                    if(ans[next]>dist+1) {
                        ans[next]=dist+1;
                        qu.push(next);
                    }
                }
            }
            dist+=1;
        }
        return ans;
    }
    bool dfs(int u,int pre) {   //环检测，并记录唯一的环cycle
        if(visited[u]) return true;
        visited[u]=true;
        for(int v:adj[u]) {       					//存在(u,v)边
            if(v==pre) continue;      			//跳过(u,v,u)的环
            path.push_back(v);					//将v添加到path中
            if(dfs(v,u)) return true;				//找到后返回true
            path.pop_back();         			//回溯
        }
        return false;
    }
    vector<int> findCycle(int n) {
        vector<int> cycle;                    //存放环上的顶点
        path={};
        visited=vector<bool>(n,false);
        for(int i=0;i<n;i++) {
            if(visited[i]) continue;
            path.push_back(i);
            if(dfs(i,-1)) break;
        }
        int last=path.back();
        path.pop_back();
        cycle.push_back(last);
        while(!path.empty() &&  path.back()!=last) {
            cycle.push_back(path.back());
            path.pop_back();
        }
        return cycle;
    }
};

