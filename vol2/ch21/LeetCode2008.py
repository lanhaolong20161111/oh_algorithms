class Solution:
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        radj=[[] for _ in range(n+1)]    			#逆邻接表
        for r in rides:                   			#建立radj
            radj[r[1]].append([r[0],r[1]-r[0]+r[2]])
        dp=[0]*(n+1)
        for i in range(1,n+1):
            dp[i]=dp[i-1]
            for [s,p] in radj[i]:
                dp[i]=max(dp[i],dp[s]+p)
        return dp[n]
