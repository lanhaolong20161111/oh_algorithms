class Solution:
  def minFallingPathSum(self, grid: List[List[int]]) -> int:
    INF=0x3f3f3f3f
    n=len(grid)
    dp=[[0 for _ in range(0,n)] for _ in range(0,n)]
    for j in range(0,n):  #第0行:边界条件
      dp[0][j]=grid[0][j]
    for i in range(1,n):    #考虑第i行
      for j in range(0,n):  #考虑第i行的第j列
        tmp=INF
        for k in range(0,n):   #考虑第i-1行的第k列
          if k!=j:tmp=min(tmp,dp[i-1][k])
        dp[i][j]=grid[i][j]+tmp
    return min(dp[n-1])   #返回dp[n-1]中的最小值
