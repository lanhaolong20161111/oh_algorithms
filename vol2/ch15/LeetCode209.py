class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n=len(nums)
        presum=[0]*(n+1)
        presum[0]=0
        for i in range(1,n+1):
            presum[i]=presum[i-1]+nums[i-1]
        ans=n+1
        low,high=0,0
        while high<n:
            if presum[high+1]-presum[low]>=target:
                ans=min(ans,high-low+1)
                low+=1
            else: high+=1
        if ans==n+1:return 0
        return ans
