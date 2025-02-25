from sortedcontainers import SortedList
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        n=len(nums)
        sl=SortedList()
        ans=[0]*n
        for i in range(n-1,-1,-1):
            ans[i]=sl.bisect_left(nums[i])
            sl.add(nums[i])
        return ans
