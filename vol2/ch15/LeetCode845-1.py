class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        n=len(arr)
        if n<3:return 0
        ans=0
        for i in range(1,n-1):
            cur=self.center(arr,i)
            ans=max(ans,cur)
        return ans

    def center(self,a,i):
        left=0
        for j in range(i-1,-1,-1):
            if a[j]<a[j+1]:left+=1
            else: break
        right=0
        for j in range(i+1,len(a)):
            if a[j-1]>a[j]:right+=1
            else: break
        if left>0 and right>0:
            return left+right+1
        return 0
