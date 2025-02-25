class Solution {
  const int INF=0x3f3f3f3f;
public:
  int coinChange(vector<int>& coins, int amount)  {
    int n=coins.size();
    auto dp=vector<vector<int>>(n+1,vector<int>(amount+1,INF));
          dp[0][0]=0;
          for (int i=1;i<=n;i++) {
            for (int j=0;j<=amount;j++) {
                if(j<coins[i-1])      //硬币i-1装不下，不能装入
                        dp[i][j]=dp[i-1][j];
                    else                            //可以选择装入和不装入
                        dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
              }
          }
          return dp[n][amount]==INF?-1:dp[n][amount];
      }
};

