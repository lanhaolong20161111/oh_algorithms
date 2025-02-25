class Solution:
  def getMoneyAmount(self, n: int) -> int:
    INF=0x3f3f3f3f
    if n<=3:return n-1
    dp=[[0 for _ in range(n+1)] for _ in range(n+1)]
    for i in range(1,n+1):dp[i][i]=0
    for length in range(2,n+1):
      for i in range(1,n-length+2):
        j=i+length-1
        minCost=INF           #为了求min，初始置为∞
        for m in range(i,j): #枚举[i,j]区间中的猜测点m
          minCost=min(minCost,m+max(dp[i][m-1],dp[m+1][j]))
        dp[i][j]=minCost
    return dp[1][n]
