class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k=0
        for i in range(1,len(nums)):			#首先保留nums[0]
            if nums[i]==nums[i-1]:k+=1      #nums[i]为要删除的元素
            else: nums[i-k]=nums[i]         #nums[i]为要保留的元素
        return len(nums)-k
