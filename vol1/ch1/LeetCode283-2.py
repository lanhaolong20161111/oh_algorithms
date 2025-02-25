class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        n,k=len(nums),0
        for i in range(0,n):
            if nums[i]==0: k+=1            #nums[i]为要删除的元素
            else: nums[i-k]=nums[i]         #nums[i]为要保留的元素
        for i in range(n-k,n):
            nums[i]=0
