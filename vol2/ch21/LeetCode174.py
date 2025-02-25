class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        INF=0x3f3f3f3f
        m,n=len(dungeon),len(dungeon[0])
        dp=[[INF for _ in range(0,n+1)] for _ in range(0,m+1)]
        dp[m][n-1],dp[m-1][n]=1,1
        for i in range(m-1,-1,-1):
            for j in range(n-1,-1,-1):
                mind=min(dp[i+1][j],dp[i][j+1])
                dp[i][j]=max(mind-dungeon[i][j],1)
        return dp[0][0]
