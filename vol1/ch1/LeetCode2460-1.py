class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n,k=len(nums),0
        for i in range(0,n):
            if nums[i]==0:       #跳过0元素
                continue
            else:
                if i<n-1 and nums[i]==nums[i+1]:
                    nums[i],nums[i+1]=2*nums[i],0    #修改操作
                nums[k]=nums[i]    #将非0元素插入到nums[k]处
                k+=1
        for j in range(k,n):        #末尾补0
            nums[j]=0
        return nums
