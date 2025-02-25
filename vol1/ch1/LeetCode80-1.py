class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n=len(nums)
        if n<=2: return n
        k=2
        for i in range(2,n):
            if not (nums[k-2]==nums[k-1] and nums[i]==nums[k-1]):
                nums[k]=nums[i]                 #nums[i]为保留元素
                k+=1
        return k
