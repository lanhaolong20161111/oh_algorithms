class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n=len(nums)
        base=self.getBase(nums)             #获取基准位置
        low,high=0,n-1
        while low<=high:                     #查找区间至少有一个元素时循环
            mid=(low+high)//2
            i=(mid+base)%n                 #a[mid]=nums[i]
            if target==nums[i]:return i
            if target>nums[i]:low=mid+1
            else:high=mid-1
        return -1
    def getBase(self,nums):                  #查找基准位置
        low,high=0,len(nums)-1
        while low<high:
            mid=(low+high)//2
            if nums[mid]<nums[high]:high=mid        #向左逼近
            else:low=mid+1                  #在右区间中查找
        return low
