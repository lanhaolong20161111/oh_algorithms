class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k=1												#首先保留nums[0]
        for i in range(1,len(nums)):
            if nums[i]!=nums[i-1]:#将保留的元素重新插入
                nums[k]=nums[i]
                k+=1
        return k