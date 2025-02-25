class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n=len(nums)
        if n==1:return True
        if nums[0]==0:return False
        dp=nums[0]
        for i in range(1,n-1):
            dp=max(dp,i+nums[i])
            if dp>=n-1:return True
            if dp==i:return False
        return True
