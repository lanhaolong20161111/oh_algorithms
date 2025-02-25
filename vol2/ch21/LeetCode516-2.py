class Solution:
	def longestPalindromeSubseq(self, s: str) -> int:
		n=len(s)
		if n==1:return 1
		dp=[[0 for _ in range(n)] for _ in range(n)]
		for i in range(0,n):dp[i][i]=1				#区间长度为1的情况
		for i in range(0,n-1):						#区间长度为2的情况
			if s[i]==s[i+1]:dp[i][i+1]=2
			else: dp[i][i+1]=1
		for i in range(n-1,-1,-1):
			for j in range(i+1,n):  				#枚举s[i..j]
				if j-i+1>=3:							#区间长度至少为3的情况
				  if s[i]==s[j]:
					  dp[i][j]=dp[i+1][j-1]+2
				  else:
					  dp[i][j]=max(dp[i][j-1],dp[i+1][j])
		return dp[0][n-1]
