class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        k=0
        for i in range(0,len(nums)):
            if nums[i]!=0:           #将保留的元素重新插入
                nums[k]=nums[i]
                k+=1
        for i in range(k,len(nums)):
            nums[i]=0
