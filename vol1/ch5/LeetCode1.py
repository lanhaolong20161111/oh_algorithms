class Solution:
    def twoSum(self,nums:List[int],target:int)->List[int]:
        hmap={}                                         #定义一个字典
        for i,d in enumerate(nums):
            if target-d in hmap:                            #找到后返回结果
                return hmap[target-d],i
            hmap[d]=i                               #添加到hmap
