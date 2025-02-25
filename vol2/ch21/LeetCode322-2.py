class Solution:
  def coinChange(self, coins: List[int], amount: int) -> int:
    n=len(coins)
    INF=0x3f3f3f3f
    dp=[INF for _ in range(amount+1)]
    dp[0]=0
    for i in range(1,n+1):
      for j in range(0,amount+1):
        if j>=coins[i-1]: #可以选择装入和不装入
          dp[j]=min(dp[j],dp[j-coins[i-1]]+1)
    return dp[amount] if dp[amount]!=INF else -1
