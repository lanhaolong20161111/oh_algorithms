class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        hmap={}
        hmap[0]=-1
        presum,ans=0,0 
        for j in range(0,len(nums)):
            presum+=nums[j]
            rest=presum-k
            if rest in hmap:ans=max(ans,j-hmap[rest])
            if presum not in hmap:hmap[presum]=j
        return ans 
