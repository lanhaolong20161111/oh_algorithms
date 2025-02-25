class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        n=len(nums)
        if n<2:return False
        hmap={}
        hmap[0]=-1
        presum=0 
        for j in range(0,n):
            presum=(presum+nums[j])%k
            if presum in hmap:
                if j-hmap[presum]>=2:return True
            else:hmap[presum]=j
        return False
