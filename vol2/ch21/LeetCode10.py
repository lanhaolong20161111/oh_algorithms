class Solution:
  def isMatch(self, s: str, p: str) -> bool:
    m,n=len(s),len(p)
    dp=[[False for _ in range(n+1)] for _ in range(m+1)]
    dp[0][0]=True
    for j in range(1,n+1): 
      if p[j-1]=='*' and j-2>=0 and dp[0][j-2]: 
        dp[0][j]=True
    for i in range(1,m+1):
      for j in range(1,n+1):
        if p[j-1]!='*':
          if p[j-1]=='.' or s[i-1]==p[j-1]:
            dp[i][j]=dp[i-1][j-1]
        else:     #p[j-1]=='*'
          dp[i][j]=dp[i][j-2]
          if p[j-2]=='.'  or s[i-1]==p[j-2]:
            dp[i][j]=dp[i][j] or dp[i-1][j]
    return dp[m][n]
