class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        n=len(arr)
        if n<3:return 0
        left=[0]*n
        for i in range(1,n):
            left[i]=(left[i-1]+1 if arr[i-1]<arr[i] else 0)       
        right=[0]*n
        for i in range(n-2,-1,-1):
            right[i]=(right[i+1]+1 if arr[i+1]<arr[i] else 0)
        ans=0
        for i in range(n):
            if left[i]>0 and right[i]>0:
                ans=max(ans,left[i]+right[i]+1)
        return ans
