class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low,high=0,len(nums)-1
        while low<=high:                     #查找区间至少有一个元素时循环
            mid=(low+high)//2
            if nums[mid]==target:           #找到后直接返回mid
                return mid
            if nums[mid]<nums[high]:         #nums[mid]属于右有序段
                if nums[mid]<=target and target<=nums[high]:
                    low=mid+1                  #右有序段后面部分(有序)中查找
                else:
                    high=mid-1                 #在nums[low..mid-1]中查找
            else:                                  #nums[mid]属于左有序段
                if nums[low]<=target and target<=nums[mid]:
                    high=mid-1                 #在左有序段前面部分(有序)中查找
                else:
                    low=mid+1                  #在nums[mid+1..high]中查找
        return -1
