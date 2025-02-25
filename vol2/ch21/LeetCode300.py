class Solution:
  def lengthOfLIS(self, nums: List[int]) -> int:
    n=len(nums)
    dp=[0]*n
    ans=0 
    for i in range(0,n):
      dp[i]=1
      for j in range(0,i):
        if nums[i]>nums[j]:
          dp[i]=max(dp[i],dp[j]+1)
      ans=max(ans,dp[i])
    return ans
