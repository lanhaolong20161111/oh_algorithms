class Solution:
    def numDecodings(self, s: str) -> int:
        n=len(s)
        dp=[0 for _ in range(0,n+1)]
        dp[0]=1
        for i in range(1,n+1):
            if s[i-1]!='0':
                dp[i]=dp[i-1]
            if i>1 and s[i-2]!='0' and int(s[i-2])*10+int(s[i-1])<=26:
                dp[i]+=dp[i-2]
        return dp[n]
