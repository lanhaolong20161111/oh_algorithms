class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        self.quicksort(nums,0,len(nums)-1)
        return nums
    def partition2(self,a,s,t):  #划分算法2（用于递增排序）
        base=a[(s+t)//2]
        i,j=s,t
        while i<=j:
            while i<=j and a[i]<base:i+=1    #从左向右跳过小于base的元素
            while i<=j and a[j]>base: j-=1    #从右向左跳过大于base的元素
            if i<=j:
                a[i],a[j]=a[j],a[i]           #a[i]和a[j]交换
                i,j=i+1,j-1
        return [j,i]
    def quicksort(self,a,s,t):      #快速排序
        if s<t:
            [j,i]=self.partition2(a,s,t) 
            self.quicksort(a,s,j)
            self.quicksort(a,i,t)
