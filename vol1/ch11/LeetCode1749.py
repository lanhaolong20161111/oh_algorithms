class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        n=len(nums)
        presum=[0]*n
        presum[0]=nums[0]
        maxpre,minpre=presum[0],presum[0]
        for i in range(1,n):
            presum[i]=presum[i-1]+nums[i]
            maxpre=max(maxpre,presum[i])
            minpre=min(minpre,presum[i])
        if minpre>=0:
            return maxpre
        if maxpre<=0:
            return abs(minpre)
        return maxpre-minpre
