class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        j=-1
        for i in range(0,len(nums)):
            if nums[i]!=val:              #nums[i]为保留的元素
                j+=1                         #扩大保留元素区间
                if j!=i:                   #序号i和j的两个元素交换
                    nums[i],nums[j]=nums[j],nums[i] 
        return j+1                     #新数组长度为j+1
