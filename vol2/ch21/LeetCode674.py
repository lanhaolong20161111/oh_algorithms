class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        n=len(nums)
        dp=[0]*n
        dp[0]=1
        ans=dp[0]
        for i in range(1,n):
            dp[i]=1
            if nums[i]>nums[i-1]:
                dp[i]=max(dp[i],dp[i-1]+1)
            ans=max(ans,dp[i])
        return ans
