class Solution:
  def findTargetSumWays(self, nums: List[int], target: int) -> int:
    n=len(nums)
    s=sum(nums)
    if abs(target)>s:return 0
    if (s+target)%2==1:return 0
    W=(s+target)//2
    dp=[0]*(W+1)
    dp[0]=1
    for i in range(1,n+1):
      for r in range(W,nums[i-1]-1,-1): #r从大到小循环（重点）
        dp[r]+=dp[r-nums[i-1]]
    return dp[W]
