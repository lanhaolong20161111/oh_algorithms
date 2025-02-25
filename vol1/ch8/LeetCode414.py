from sortedcontainers import SortedSet
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        tset=SortedSet()						#默认递增排列
        for x in nums:
            tset.add(x)
        if len(tset)<3:
            return tset[-1]
        else:
            return tset[-3]
