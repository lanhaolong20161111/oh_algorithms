class Solution:
    def numDecodings(self, s: str) -> int:
        mod=1000000007;   
        n=len(s)
        dp=[0 for _ in range(0,n+1)]
        dp[0]=1
        dp[1]=9 if s[0]=='*' else 1
        if s[0]=='0':dp[0],dp[1]=0,0
        for i in range(2,n+1):
            if s[i-1]!='*':
                if s[i-1]!='0':
                    dp[i]=dp[i-1]
                if s[i-2]=='1':
                    dp[i]+=dp[i-2]
                elif s[i-2]=='2' and s[i-1]<'7':
                    dp[i]+=dp[i-2]
                elif s[i-2]=='*':
                    if s[i-1]<'7':
                        dp[i]+=(dp[i-2]*2)
                    else:
                        dp[i]+=dp[i-2]
            else:
                dp[i]=dp[i-1]*9
                if s[i-2]=='1':
                    dp[i]+=dp[i-2]*9
                elif s[i-2]=='2':
                    dp[i]+=dp[i-2]*6
                elif s[i-2]=='*':
                    dp[i]+=dp[i-2]*15
            dp[i] %= mod
        return dp[n]
