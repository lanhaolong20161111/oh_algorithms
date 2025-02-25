class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        auto dp=vector<vector<int>>(n+1,vector<int>(amount+1,0));
        for (int i=0;i<=n;i++)
            dp[i][0]=1;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=amount;j++) {
                if (j<coins[i-1])           //硬币i-1装不下，不能装入
                    dp[i][j]=dp[i-1][j];
                else                        //可以选择装入和不装入
                    dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                }
        }
        return dp[n][amount];
    }
};

