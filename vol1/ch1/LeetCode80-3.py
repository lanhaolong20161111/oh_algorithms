class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n=len(nums)
        if n<=2: return n
        j=1                         #首先保留nums[0]和nums[1]
        for i in range(2,n):
            if  not (nums[j-1]==nums[j] and nums[i]==nums[j]):
                j+=1                        #扩大保留元素区间
                if j!=i:nums[i],nums[j]=nums[j],nums[i] 
        return j+1
