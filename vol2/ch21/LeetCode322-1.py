class Solution:
  def coinChange(self, coins: List[int], amount: int) -> int:
    n=len(coins)
    INF=0x3f3f3f3f
    dp=[[INF for _ in range(amount+1)] for _ in range(n+1)]
    dp[0][0]=0
    for i in range(1,n+1):
      for j in range(0,amount+1):
        if j<coins[i-1]:  #硬币i-1装不下，不能装入
          dp[i][j]=dp[i-1][j]
        else: #可以选择装入和不装入
          dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]+1)
    return dp[n][amount] if dp[n][amount]!=INF else -1
