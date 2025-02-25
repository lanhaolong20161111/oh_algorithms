class Solution {
    const int INF=0x3f3f3f3f;
public:
    int strangePrinter(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,INF));
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        for(int i=n-1;i>=0;i--) {
            for(int j=i+1;j<n;j++) {       //Ã¶¾ÙÇø¼äs[i..j]
                if (s[i]==s[j])
                    dp[i][j]=dp[i][j-1];
                else {
                    for (int k=i;k<j;k++) 
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};

