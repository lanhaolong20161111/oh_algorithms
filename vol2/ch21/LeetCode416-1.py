class Solution:
  def canPartition(self, nums: List[int]) -> bool:
    n=len(nums)
    if n<2:return False  #若元素个数小于2，则不能分割
    s,maxe=sum(nums),max(nums)
    if s%2!=0:return False   #如果和是奇数，则不能分割
    W=s//2          #W为元素和的一半
    if maxe>W:return False   #最大元素大于W，则不能分割
    dp=[0]*(W+1)                        #一维动态规划数组
    for i in range(1,n+1):
      for r in range(W,nums[i-1]-1,-1):      #r从大到小循环（重点）
        dp[r]=max(dp[r],dp[r-nums[i-1]]+nums[i-1])
    return dp[W]==W
