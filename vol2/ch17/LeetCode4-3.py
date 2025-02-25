class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m,n=len(nums1),len(nums2)
        k=(m+n)//2
        if (m+n)%2==0:                                 #总元素个数为偶数
            mid1=self.Findk(nums1,nums2,k)
            mid2=self.Findk(nums1,nums2,k+1)
            return (mid1+mid2)/2.0
        else:return self.Findk(nums1,nums2,k+1)       #总元素个数为奇数
    def Findk(self,a,b,k):      #在a,b升序数组中求第k小元素
        m,n=len(a),len(b)
        i,j=0,0                                         #i和j分别遍历a和b的指针
        while k>1:                                 #循环直到k缩小为1
            av=a[i+k//2-1] if i+k//2-1<m else 1000005			#用1000005表示∞
            bv=b[j+k//2-1] if j+k//2-1<n else 1000005
            if av<bv:i+=k//2
            else:j+=k//2
            k-=k//2                                 #每次循环k递减k/2
        if i>=m:return b[j+k-1];                #若a空，直接返回b中的第k小元素
        if j>=n:return a[i+k-1];                #若b空，直接返回a中的第k小元素
        return min(a[i],b[j]);                             #两数组均不为空(k==1)，返回最小值
