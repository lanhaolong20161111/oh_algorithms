class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        f=self.lowerbound(nums,target)
        if f==len(nums) or nums[f]!=target:   #不存在target的元素的情况
            return [-1,-1]
        e=self.upperbound(nums,target)        #存在target元素时
        return [f,e-1]           								#结果为[f,e-1]
    def lowerbound(self,nums,k):   #查找第一个大于等于k的序号
        low,high=0,len(nums)                      #初始查找区间为[0,n] 
        while low<high:                     #查找区间至少有2个元素时循环
            mid=(low+high)//2
            if k<=nums[mid]:
                high=mid                       #在左区间(含mid)中查找
            else:
                low=mid+1                      #在右区间中查找(不含mid)
        return low                             #返回low
    def upperbound(self,nums,k):   #查找第一个大于k的序号
        low,high=0,len(nums)                       #初始查找区间为[0,n]
        while low<high:                      #查找区间至少有2个元素时循环
            mid=(low+high)//2
            if k<nums[mid]:
                high=mid                   #在左区间(含mid)中查找
            else:
                low=mid+1                  #k>=nums[mid]在右区间中查找
        return low                                         #返回low
