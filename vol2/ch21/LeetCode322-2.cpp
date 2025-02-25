class Solution {
  const int INF=0x3f3f3f3f;
public:
      int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount+1,INF);
          dp[0]=0;
          for (int i=1;i<=n;i++) {
            for (int j=0;j<=amount;j++) {
                if(j>=coins[i-1])	//可以选择装入和不装入
                        dp[j]=min(dp[j],dp[j-coins[i-1]]+1);
              }
          }
          return dp[amount]==INF?-1:dp[amount];
      }
};

