    struct cmp{
        bool operator()(const pair<int,int> s1,const pair<int,int> s2) {
          return s1.second>s2.second;			//用于按second越小越优先出队
        }
    };
class Solution {
public:
    int minCostToSupplyWater(int n,vector<int>& wells,vector<vector<int>>& pipes) {
        if(n==1) return wells[n-1];
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto e:pipes) {
          int a=e[0],b=e[1],w=e[2];
          adj[a].push_back({b,w});
          adj[b].push_back({a,w});
        } 
        for(int i=1;i<=n;i++) {					//建立超级源点0
            adj[0].push_back({i,wells[i-1]});
            adj[i].push_back({0,wells[i-1]});
        }
        vector<bool> U(n+1,false);
        int ans=0;          //存放答案
        int k=0;            //累计选择的边数
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pqu;
        U[0]=true;
        for(auto e:adj[0]) pqu.push(e);
        while(!pqu.empty()) {
            int v=pqu.top().first, w=pqu.top().second;
            pqu.pop();
            if(!U[v]) {
                U[v]=true;
                ans+=w;
                k++;
                if(k==n) return ans;
                for(auto e:adj[v]) pqu.push(e);
            }
        }
        return -1;
    }
};

