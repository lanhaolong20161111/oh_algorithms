class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        n=len(nums)
        if n==1:return nums[0]
        return self.smallk(nums,n-k+1)
    def smallk(self,a,k):				#查找到区间仅含一个元素
        low,high=min(a),max(a)
        while low<high:              #区间中至少有两个元素时循环
            mid=low+(high-low)//2   #保证长度为2时找左中间元素
            cnt=0
            for e in a:
                if e<=mid:cnt+=1
            if cnt>=k:                  #说明mid大了
                high=mid               #在左区间中继续查找
            else:                        #说明mid小了
                low=mid+1              #在右区间中继续查找
        return low                     #或者return high
