class Solution {
    vector<vector<int>> adj;
    vector<int> dp1,dp2;
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        adj=vector<vector<int>>(n,vector<int>());
        dp1=vector<int>(n,0);
        dp2=vector<int>(n,0);
        for(auto edge:edges) {
            int a=edge[0],b=edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0,-1);								//初始时0看成根，其前驱为-1
        int ans=0;
        for (int i=0;i<n;i++)
            ans=max(ans,dp1[i]+dp2[i]);
        return ans;
    }
    void dfs(int root,int pre) {         //树形DP
        for(auto &v:adj[root]) {
            if(v==pre) continue;        //跳过结点root的父结点
            dfs(v,root);
            int d=dp1[v]+1;             //d为root的路径长度
            if(d>=dp1[root]) {				//若d大于原最大路径长度
                dp2[root]=dp1[root];
                dp1[root]=d;
            }
            else if(d>dp2[root])				//若d大于原次大路径长度
                dp2[root]=d;
        }
    }
};

