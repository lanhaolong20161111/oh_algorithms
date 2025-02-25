class Solution:
    def mergeStones(self, stones: List[int], K: int) -> int:
        INF=0x3f3f3f3f3f
        n=len(stones)
        if (n-1)%(K-1):return -1
        presum=[0]*(n+1)
        presum[0]=0
        for i in range(1,n+1):    #求前缀和
            presum[i]=presum[i-1]+stones[i-1]
        dp=[[INF for _ in range(n+1)] for _ in range(n+1)]
        for i in range(0,n+1):
            dp[i][i]=0
        for length in range(2,n+1):
            for i in range(0,n-length+1):
                j=i+length-1
                m=i
                while m<j:
                    dp[i][j]=min(dp[i][j],dp[i][m]+dp[m+1][j])
                    m+=K-1
                if (length-1)%(K-1)==0: #如果区间能够合并则合并
                    dp[i][j]+=presum[j+1]-presum[i] #区间[i,j]的K堆合并成一堆
        return dp[0][n-1]
