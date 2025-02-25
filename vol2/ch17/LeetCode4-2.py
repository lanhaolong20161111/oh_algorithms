class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m,n=len(nums1),len(nums2)
        if m==0:return (nums2[(n+1)//2-1]+nums2[(n+2)//2-1])/2.0
        if n==0:return (nums1[(m+1)//2-1]+nums1[(m+2)//2-1])/2.0
        mid1=(m+n+1)//2
        mid2=(m+n+2)//2
        return (self.Findk(nums1,m,nums2,n,mid1)+self.Findk(nums1,m,nums2,n,mid2))/2.0
    def Findk(self,a,m,b,n,k):  #在a,b升序数组中求第k小元素
        if m>n:                 #保证前一个数组元素个数比少
            return self.Findk(b,n,a,m,k)
        if m==0:
            return b[k-1]
        if k==1:
            return b[0] if a[0]>=b[0] else a[0]
        i=min(m,k//2)     #当数组a中没有k/2个元素时取m
        j=k-i 
        if a[i-1]==b[j-1]:
            return a[i-1]
        elif a[i-1]>b[j-1]:
            return self.Findk(a,m,b[j:],n-j,k-j)
        else:                        #a[i-1]<b[j-1]
            return self.Findk(a[i:],m-i,b,n,k-i)
