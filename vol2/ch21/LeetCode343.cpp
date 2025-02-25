class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++) {
            for(int j=1;j<i;j++) {
                dp[i]=max(dp[i],max((i-j)*dp[j],(i-j)*j));
            }
        }
        return dp[n];
    }
};

