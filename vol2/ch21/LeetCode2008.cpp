class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<vector<pair<int,int>>> radj(n+1);    //���ڽӱ�
        for (auto r:rides) {                        //����radj
            radj[r[1]].push_back({r[0],r[1]-r[0]+r[2]});
        }
        vector<long long> dp(n+1,0);
        for (int i=1;i<=n;i++) {
            dp[i]=dp[i-1];
            for (auto [s,p]:radj[i])
                dp[i]=fmax(dp[i],dp[s]+p);
        }
        return dp[n];
    }
};

