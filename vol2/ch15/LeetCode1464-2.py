class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max1,max2=-1,-1
        for d in nums:
            if d>max1:
                max2=max1
                max1=d
            elif d>max2:
                max2=d
        return (max1-1)*(max2-1)
