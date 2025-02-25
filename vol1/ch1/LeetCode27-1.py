class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k=0
        for i in range(0,len(nums)):
            if nums[i]!=val:        						#将保留的元素重新插入
                nums[k]=nums[i]
                k+=1
        return k
