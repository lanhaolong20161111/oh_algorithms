class Solution:
    def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
        mod=1000000007
        m,n=len(nums1),len(nums2)
        dp1,dp2=0,0
        i,j=1,1
        while i<=m and j<=n:
            if nums1[i-1]<nums2[j-1]:
                dp1=dp1+nums1[i-1]
                i+=1
            elif nums1[i-1]>nums2[j-1]:
                dp2=dp2+nums2[j-1]
                j+=1
            else:
                cmax=max(dp1,dp2)+nums1[i-1]
                dp1=dp2=cmax
                i,j=i+1,j+1
        while i<=m:
            dp1=dp1+nums1[i-1]
            i+=1
        while j<=n:
            dp2=dp2+nums2[j-1]
            j+=1
        return max(dp1,dp2) % mod
