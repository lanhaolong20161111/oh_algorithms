class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k=0
        for i in range(0,len(nums)):
            if nums[i]==val:k+=1             #nums[i]为要删除的元素
            else: nums[i-k]=nums[i]         #nums[i]为要保留的元素
        return len(nums)-k
