class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        n=len(nums)
        presum=[0]*(n+1)
        presum[0]=0
        for i in range(1,n+1):
            presum[i]=presum[i-1]+nums[i-1]
        ans=n
        for i in range(0,n):
            if presum[i]==presum[n]-presum[i+1]:
                ans=i
                break
        if ans==n:return -1
        else: return ans
