class Solution:
    def strangePrinter(self, s: str) -> int:
        INF=0x3f3f3f3f
        n=len(s)
        dp=[[INF for _ in range(n)] for _ in range(n)]
        for i in range(n):dp[i][i]=1
        for i in range(n-1,-1,-1):
            for j in range(i+1,n):  #枚举区间s[i..j]
                if s[i]==s[j]:
                    dp[i][j]=dp[i][j-1]
                else:
                    for k in range(i,j):
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j])
        return dp[0][n-1]
