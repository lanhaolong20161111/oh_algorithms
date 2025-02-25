class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hset=set()
        for x in nums:
            if x in hset:
                return True
            hset.add(x)
        return False
