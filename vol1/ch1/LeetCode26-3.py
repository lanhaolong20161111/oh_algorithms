class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        j=0            #首先保留nums[0]
        for i in range(1,len(nums)):
            if nums[i]!=nums[j]:            #nums[i]为保留的元素
                j+=1                         #扩大保留元素区间
                if j!=i:nums[i],nums[j]=nums[j],nums[i]
        return j+1
