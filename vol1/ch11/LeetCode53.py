class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n=len(nums)
        presum,minsum=[0]*(n+1),[0]*(n+1)
        presum[0]=0
        for j in range(1,n+1):
            presum[j]=presum[j-1]+nums[j-1]
        minsum[0]=0
        for j in range(1,n+1):
            minsum[j]=min(minsum[j-1],presum[j]);
        ans=-0x3f3f3f3f
        for j in range(1,n+1):
            ans=max(ans,presum[j]-minsum[j-1])
        return ans  
