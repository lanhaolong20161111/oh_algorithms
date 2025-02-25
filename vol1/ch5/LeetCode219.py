class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hmap={}                                 #定义一个字典
        for i,d in enumerate(nums):
            if d in hmap and i-hmap[d]<=k:      #找到后返回结果
                return True
            else:
                hmap[d]=i                       #添加到hmap
        return False
