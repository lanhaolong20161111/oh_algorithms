class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        hmap={}
        hmap[0]=1
        presum,ans=0,0 
        for j in range(0,len(nums)):
            presum+=nums[j]
            rest=presum-k; 
            if rest in hmap: 
                ans+=hmap[rest]
            if presum in hmap:hmap[presum]+=1
            else: hmap[presum]=1
        return ans
