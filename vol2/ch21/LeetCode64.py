class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
      m,n=len(grid),len(grid[0])
      dp=[[0 for _ in range(0,n)] for _ in range(0,m)]
      dp[0][0]=grid[0][0]           #起始位置：边界条件①
      for i in range(1,m):        #第0列的情况：边界条件②
        dp[i][0]=dp[i-1][0]+grid[i][0]
      for j in range(1,n):          #第0行的情况：边界条件③
        dp[0][j]=dp[0][j-1]+grid[0][j]
      for i in range(1,m):          #其他行列的情况
        for j in range(1,n):
          dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j]
      return dp[m-1][n-1]
