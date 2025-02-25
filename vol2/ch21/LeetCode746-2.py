class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n=len(cost)
        dp=[0]*3
        dp[0]=dp[1]=0
        for i in range(2,n+1):
            dp[i%3]=min(dp[(i-1)%3]+cost[i-1],dp[(i-2)%3]+cost[i-2])
        return dp[n%3]