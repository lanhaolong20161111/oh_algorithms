class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n=len(arr)
        c,cnt=arr[0],0
        for  i in range(0,n):
            if arr[i]==c:
                cnt+=1
                if cnt*4>n: return c
            else:
                c,cnt=arr[i],1
