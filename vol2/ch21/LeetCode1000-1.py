class Solution:
    def mergeStones(self, stones: List[int], K: int) -> int:
        INF=0x3f3f3f3f3f
        n=len(stones)
        if (n-1)%(K-1):return -1
        presum=[0]*(n+1)
        presum[0]=0
        for i in range(1,n+1):    #求前缀和
            presum[i]=presum[i-1]+stones[i-1]
        dp=[[[INF]*(K+1) for _ in range(n+1)] for _ in range(n+1)]
        for i in range(0,n+1):
            dp[i][i][1]=0
        for length in range(2,n+1):
            for i in range(0,n-length+1):
                j=i+length-1
                for k in range(1,K+1):
                    for m in range(i,j):
                        dp[i][j][k]=min(dp[i][j][k],dp[i][m][1]+dp[m+1][j][k-1])
                dp[i][j][1]=dp[i][j][K]+presum[j+1]-presum[i] #区间[i,j]的K堆合并成一堆
        return dp[0][n-1][1]
