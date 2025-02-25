typedef long long LL;
class Solution {
    const int mod=1000000007;
public:
    int numDistinct(string s, string t) {
        int m=s.size(),n=t.size();
        auto dp=vector<vector<LL>>(m+1,vector<LL>(n+1,0));
        for(int i=0;i<=m;i++) dp[i][0]=1;
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]) {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                    dp[i][j]%=mod;
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return (int)dp[m][n];
    }
};

