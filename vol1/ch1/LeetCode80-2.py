class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n=len(nums)
        if n<=2: return n
        k=0
        for i in range(2,n):
            if  not (nums[i-k-2]==nums[i-k-1] and nums[i]==nums[i-k-1]):
                nums[i-k]=nums[i]
            else:
                k+=1
        return n-k
