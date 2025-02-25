class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m,n=len(nums1),len(nums2)
        c=[]
        for x in nums1:c.append(x)
        for x in nums2:c.append(x)
        c.sort()
        k=(m+n)//2
        if (m+n)%2==0:              #总元素个数为偶数的情况
            return (c[k-1]+c[k])/2.0
        else:                         #总元素个数为奇数的情况
            return c[k]
