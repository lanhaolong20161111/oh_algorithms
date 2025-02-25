class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        n=len(s)
        dp=[[0 for j in range(n)] for i in range(n)]
        ans=0
        for i in range(n):
            for j in range(i+1,n):
                if s[i]==s[j]:
                    if i==0:dp[i][j]=1
                    else:dp[i][j]=dp[i-1][j-1]+1
                ans=max(ans,dp[i][j])
        return ans
