class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n=len(nums)
        ans=[0]*n
        ans[0]=nums[0]                #求前缀积
        for i in range(1,n):
            ans[i]=ans[i-1]*nums[i]
        ans[n-1]=ans[n-2]
        postd=nums[n-1]                 #求后缀积
        for k in range(n-2,0,-1):
            ans[k]=ans[k-1]*postd
            postd*=nums[k]
        ans[0]=postd
        return ans
