class Solution:
  def longestValidParentheses(self,s:str) -> int:
    n=len(s)
    dp=[0]*n      #一维动态规划数组
    ans=0
    for i in range(1,n):
      if s[i]==')':
        if s[i-1]=='(':
          if i>=2:dp[i]=dp[i-2]+2
          else:dp[i]=2
        elif i-dp[i-1]>0 and s[i-dp[i-1]-1]=='(':
          if i-dp[i-1]>=2:
            dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2
          else:
            dp[i]=dp[i-1]+2
      ans=max(ans,dp[i])
    return ans
