class Solution {
    const int mod=1000000007;
public:
    int profitableSchemes(int n,int minProfit,vector<int>& group, vector<int>& profit) {
        int m=group.size();
        vector<vector<int>> dp(n+1,vector<int>(minProfit+1));
        dp[0][0]=1;
        for (int i=1;i<=m;i++) {
            for (int j=n;j>=0;j--) {
                for (int k=minProfit;k>=0;k--) {
                    if (j>=group[i-1]) {
                        dp[j][k]+=dp[j-group[i-1]][max(0,k-profit[i-1])];
                        dp[j][k]%=mod;
                    }
                }
            }
        }
        int ans=0;
        for (int j=0;j<=n;j++)
            ans=(ans+dp[j][minProfit]) % mod;
        return ans;
    }
};

