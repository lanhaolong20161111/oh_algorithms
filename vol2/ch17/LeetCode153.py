class Solution:
    def findMin(self, nums: List[int]) -> int:				#查找到区间仅含一个元素
        low,high=0,len(nums)-1
        while low<high:
            mid=(low+high)//2
            if nums[mid]<nums[high]: high=mid           #向左区间逼近
            else: low=mid+1          #在右区间中查找
        return nums[low] 
