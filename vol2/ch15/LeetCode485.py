class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans,cur=0,0
        for d in nums:
            if d==0:cur=0
            else: cur+=1
            if cur>ans:ans=cur
        return ans
