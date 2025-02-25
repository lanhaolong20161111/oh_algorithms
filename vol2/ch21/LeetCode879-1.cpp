class Solution {
    const int mod=1000000007;
public:
    int profitableSchemes(int n,int minProfit,vector<int>& group, vector<int>& profit) {
        int m=group.size();
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(minProfit+1)));
        dp[0][0][0]=1;
        for (int i=1;i<=m;i++) {
            for (int j=0;j<=n;j++) {
                for (int k=0;k<=minProfit;k++) {
                    if (j<group[i-1])
                        dp[i][j][k]=dp[i-1][j][k];
                    else {
                        dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-group[i-1]][max(0,k-profit[i-1])];
                        dp[i][j][k]%=mod;
                    }
                }
            }
        }
        int ans=0;
        for (int j=0;j<=n;j++)
            ans=(ans+dp[m][j][minProfit]) % mod;
        return ans;
    }
};

