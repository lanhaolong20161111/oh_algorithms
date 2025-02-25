class Solution:
    def minRefuelStops(self,target:int,startFuel:int,stations:List[List[int]])->int:
        n=len(stations)
        dp=[[0 for _ in range(0,n+1)] for _ in range(0,n+1)]
        for i in range(0,n+1):
            dp[i][0]=startFuel
        for i in range(1,n+1):
            for j in range(1,i+1):
                if dp[i-1][j-1]<stations[i-1][0]:
                    dp[i][j]=dp[i-1][j]       #不加油
                else:
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+stations[i-1][1])
        for j in range(0,n+1):
            if dp[n][j]>=target:return j
        return -1
