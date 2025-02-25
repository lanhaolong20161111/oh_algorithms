class Solution:
    def canJump(self, nums: List[int]) -> bool:
        return self.dfs(nums,len(nums)-1)
    def dfs(self,nums,i):       #回溯算法
        if i==0:return True
        else:
            for j in range(i-1,-1,-1):
                if j+nums[j]>=i:    #出位置j可以跳到位置i
                    return self.dfs(nums,j)
        return False
