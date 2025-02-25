class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n=len(nums)
        if n==1:return nums[0]
        return self.maxsub(nums,0,n-1) 
    def maxsub(self,a,low,high):    #分治算法
        if low==high:return a[low]           #子数组只有一个元素
        mid=(low+high)//2                   #求中间位置
        leftsum=self.maxsub(a,low,mid)          #求左边子数组之和
        rightsum=self.maxsub(a,mid+1,high)      #求右边子数组之和
        leftbordersum,maxleftbordersum=0,a[mid]
        for i in range(mid,low-1,-1):            #求左段a[i..mid]的最大子数组和
            leftbordersum+=a[i]
            maxleftbordersum=max(maxleftbordersum,leftbordersum)
        rightbordersum,maxrightbordersum=0,a[mid+1]
        for j in range(mid+1,high+1):          #求右段a[mid+1..j]的最大子数组和
            rightbordersum+=a[j]
            maxrightbordersum=max(maxrightbordersum,rightbordersum)
        ans=max(max(leftsum,rightsum),maxleftbordersum+maxrightbordersum)
        return ans
