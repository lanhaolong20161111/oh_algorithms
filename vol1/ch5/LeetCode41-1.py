class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        hset=set()
        for x in nums: hset.add(x)
        ans=1
        while ans<=len(nums)+1:
            if ans not in hset:
                break;
            ans+=1
        return ans
