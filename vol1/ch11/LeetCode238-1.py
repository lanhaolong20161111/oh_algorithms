class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n=len(nums)
        pred,postd=[0]*n,[0]*n
        pred[0]=nums[0]                #求前缀积
        for i in range(1,n):
            pred[i]=pred[i-1]*nums[i]
        postd[n-1]=nums[n-1]           #求后缀积
        for i in range(n-2,-1,-1):
            postd[i]=postd[i+1]*nums[i]
        ans=[0]*n
        ans[0]=postd[1]
        ans[n-1]=pred[n-2]
        for k in range(1,n-1):
            ans[k]=pred[k-1]*postd[k+1]
        return ans
