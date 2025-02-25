class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n=len(nums)
        for i in range(0,n):
            while nums[i]>=1 and nums[i]<=n and nums[nums[i]-1]!=nums[i]:
                self.swap(nums,i,nums[i]-1)
                #a=nums[i];b=nums[nums[i]-1]
                #nums[i]=b; nums[nums[i]-1]=a
        for i in range(0,n):
            if nums[i]!=i+1: return i+1
        return n+1
    def swap(self,nums,i,j):
        nums[i],nums[j]=nums[j],nums[i]
