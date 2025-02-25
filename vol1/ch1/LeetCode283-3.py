class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        n,j=len(nums),-1
        for i in range(0,n):
            if nums[i]!=0:              #nums[i]为保留的元素
                j+=1                        #扩大保留元素区间
                if j!=i:                   #序号i和j的两个元素交换
                    nums[i],nums[j]=nums[j],nums[i] 
        for i in range(j+1,n):
            nums[i]=0
