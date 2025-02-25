class Solution:
  def longestPalindromeSubseq(self, s: str) -> int:
    n=len(s)
    if n==1:return 1
    dp=[[0 for _ in range(n)] for _ in range(n)]
    for i in range(0,n):dp[i][i]=1        #区间长度为1的情况
    for i in range(0,n-1):            #区间长度为2的情况
      if s[i]==s[i+1]:dp[i][i+1]=2
      else: dp[i][i+1]=1
    for length in range(3,n+1):       #区间长度为3,4，…的情况
      for i in range(0,n-length+1):
        j=i+length-1
        if s[i]==s[j]:
          dp[i][j]=dp[i+1][j-1]+2
        else:
          dp[i][j]=max(dp[i][j-1],dp[i+1][j])
    return dp[0][n-1]
