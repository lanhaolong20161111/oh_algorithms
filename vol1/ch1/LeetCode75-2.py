class Solution:
    def sortColors(self, nums: List[int]) -> None:
        n=len(nums)
        x=[0]*3
        for i in range(0,n):
            x[nums[i]]+=1
        k=0
        for i in range(0,3):
            for j in range(0,x[i]):
                nums[k]=i
                k+=1
