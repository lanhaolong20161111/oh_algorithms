class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return self.quickselect(nums,0,len(nums)-1,k)
    def quickselect(self,a,s,t,k):  #在a[s..t]序列中找第k大的元素
        if s<t:                  #区间内至少存在2个元素的情况
            i=self.partition1(a,s,t)
            if k-1==i:
                return a[i]
            elif k-1<i:
                return self.quickselect(a,s,i-1,k)  #在左区间中递归查找
            else:
                return self.quickselect(a,i+1,t,k)          #在右区间中递归查找
        else: return a[k-1]
    def partition1(self,a,s,t):        #划分算法1（用于递减排序）
        i,j=s,t
        base=a[s]                      #序列中首元素作为基准
        while i<j:                      #从两端交替向中间遍历,直至i=j为止
            while i<j and a[j]<=base:j-=1  #从右向左找大于base的a[j]
            if i<j:
                a[i]=a[j]                  #将a[j]前移到a[i]的位置
                i+=1
            while i<j and a[i]>=base:i+=1                 #从左向右找小于base的a[i]
            if i<j:
                a[j]=a[i]                  #将a[i]后移到a[j]的位置
                j-=1
        a[i]=base
        return i
