class Solution {
    vector<int> answer,dp,cnt;
    vector<vector<int>> adj;
public:
    vector<int> sumOfDistancesInTree(int n,vector<vector<int>>&edges) {
        answer=vector<int>(n,0);
        cnt=vector<int>(n,0);
        dp=vector<int>(n,0);
        adj=vector<vector<int>>(n,vector<int>());
        for(auto edge:edges) {
            int a=edge[0],b=edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0,-1);
        dfs2(0,-1);
        return answer;
    }
    void dfs(int root,int pre) {    //����DP��dp��cnt
        dp[root]=0;
        cnt[root]=1;
        for(auto v:adj[root]){
            if(v==pre) continue;				//�������root�ĸ����
            dfs(v,root);
            dp[root]+=dp[v]+cnt[v];
            cnt[root]+=cnt[v];
        }
    }
    void dfs2(int root,int pre) {   					//������answer
        answer[root]=dp[root];
        for(auto v:adj[root]) {
            if(v==pre) continue;						//�������root�ĸ����
            int dpr=dp[root],dpv=dp[v];
            int cntr=cnt[root],cntv=cnt[v];
            dp[root]-=dp[v]+cnt[v];
            cnt[root]-=cnt[v];
            dp[v]+=dp[root]+cnt[root];
            cnt[v]+=cnt[root];
            dfs2(v,root);
            dp[root]=dpr,dp[v]=dpv;     //�ָ�
            cnt[root]=cntr,cnt[v]=cntv;
        }
    }
};

