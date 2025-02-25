class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans=[]
        for e in permutations(nums):
            ans.append(e)
        return ans