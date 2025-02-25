class Solution:
    def minRefuelStops(self,target:int,startFuel:int,stations:List[List[int]])->int:
        n=len(stations)
        dp=[0 for _ in range(0,n+1)]
        dp[0]=startFuel
        for i in range(1,n+1):
            for j in range(i,0,-1):
                if dp[j-1]>=stations[i-1][0]:
                    dp[j]=max(dp[j],dp[j-1]+stations[i-1][1])
        for j in range(0,n+1):
            if dp[j]>=target:return j
        return -1
