from sortedcontainers import SortedList
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        n=len(nums)
        ans=0
        sl = SortedList()
        for i in range(n-1,-1,-1):
            ans+=sl.bisect_left(nums[i])
            sl.add(2*nums[i])
        return ans
