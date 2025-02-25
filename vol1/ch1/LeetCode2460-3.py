class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n,j=len(nums),-1
        for i in range(0,n):
            if nums[i]==0:       #跳过0元素
                continue
            else:
                if i<n-1 and nums[i]==nums[i+1]:
                    nums[i],nums[i+1]=2*nums[i],0    #修改操作
                j+=1                 #将非0元素nums[i]移到保留区间
                if j!=i:nums[i],nums[j]=nums[j],nums[i]
        for i in range(j+1,n):        #末尾补0
            nums[i]=0
        return nums