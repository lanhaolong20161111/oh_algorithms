class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return self.quickselect(nums,0,len(nums)-1,k)
    def quickselect(self,a,s,t,k):
        if s>=t:return a[s]
        i,j=s,t
        base=a[(i+j)//2]
        while i<=j:
            while i<=j and a[i]>base:i+=1      #从左向右跳过大于base的元素
            while i<=j and a[j]<base:j-=1      #从右向左跳过小于base的元素
            if i<=j:
                a[i],a[j]=a[j],a[i]            #a[i]和a[j]交换
                i,j=i+1,j-1
        if s+k-1<=j:                                 #在左区间查找第k大元素
            return self.quickselect(a,s,j,k)
        if s+k-1>=i:                                 #在右区间查找第k-(i-s)大元素
            return self.quickselect(a,i,t,k-(i-s))
        return a[j+1]
