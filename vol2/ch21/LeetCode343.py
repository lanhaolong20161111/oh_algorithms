class Solution:
    def integerBreak(self, n: int) -> int:
        dp=[0]*(n+1)
        for i in range(1,n+1):
            for j in range(1,i):
                dp[i]=max(dp[i],max((i-j)*dp[j],(i-j)*j))
        return dp[n]
