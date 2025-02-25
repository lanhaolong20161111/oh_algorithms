class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans=[]
        nums=[i for i in range(1,n+1)]
        for s in combinations(nums,k):
            ans.append(s)
        return ans
