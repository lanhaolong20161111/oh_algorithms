class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        hset1=set(nums1)
        hset2=set(nums2)
        return list(hset1 & hset2)
