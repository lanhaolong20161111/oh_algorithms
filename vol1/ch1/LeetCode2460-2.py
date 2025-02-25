class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n,k=len(nums),0         #k累计为0的元素个数
        for i in range(0,n):
            if nums[i]==0:
                k+=1
            else:
                if i<n-1 and nums[i]==nums[i+1]:
                    nums[i],nums[i+1]=2*nums[i],0    #修改操作
                nums[i-k]=nums[i]               #将非0元素前移k个位置
        for j in range(n-k,n):        #末尾补0
            nums[j]=0
        return nums
