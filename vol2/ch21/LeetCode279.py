class Solution:
    def numSquares(self, n: int)->int:
        INF=0x3f3f3f3f;
        dp=[INF for _ in range(0,n+1)]
        dp[0]=0
        for i in range(1,n+1):
            j=1
            while j*j<=i:
                dp[i]=min(dp[i],dp[i-j*j]+1)
                j+=1
        return dp[n]
