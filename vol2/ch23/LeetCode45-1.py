class Solution:
  def jump(self, nums: List[int]) -> int:
    INF=0x3f3f3f3f
    n=len(nums)
    if n==1:return 0
    dp=[INF]*n
    dp[0]=0
    for j in range(1,n):
      for i in range(0,j):
        if nums[i]+i>=j:  #从位置i跳到位置j
          dp[j]=min(dp[j],dp[i]+1)
    return dp[n-1]
