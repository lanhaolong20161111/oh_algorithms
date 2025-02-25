class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m,n=len(obstacleGrid),len(obstacleGrid[0]) #行列数
        dp=[[0 for _ in range(0,n)] for _ in range(0,m)]
        for i in range(0,m):
            if obstacleGrid[i][0]==0:           #初始化第0列开头的若干空位置
                dp[i][0]=1
            else:break
        for j in range(0,n):
            if obstacleGrid[0][j]==0:           #初始化第0行开头的若干空位置
                dp[0][j]=1
            else:break;
        for i in range(1,m):
            for j in range(1,n):
                if obstacleGrid[i][j]==0:       #跳过障碍物
                    dp[i][j]=dp[i-1][j]+dp[i][j-1]
        return dp[m-1][n-1]
