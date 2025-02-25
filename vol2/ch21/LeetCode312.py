class Solution:
  def maxCoins(self, nums: List[int]) -> int:
    nums.insert(0,1)      #nums前后尾插入1，不影响结果
    nums.append(1)
    n=len(nums)
    dp=[[0 for _ in range(n)] for _ in range(n)]
    for length in range(3,n+1):
      for i in range(0,n-length+1):
        j=i+length-1;         #区间[i,j]的长度为length
        for m in range(i+1,j):    #分割点为m
          dp[i][j]=max(dp[i][j],dp[i][m]+dp[m][j]+nums[i]*nums[m]*nums[j])
    return dp[0][n-1]
