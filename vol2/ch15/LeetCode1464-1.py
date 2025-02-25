class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n,ans=len(nums),0
        for i in range(0,n-1):
            for j in range(i+1,n):
                ans=max(ans,(nums[i]-1)*(nums[j]-1))
        return ans
