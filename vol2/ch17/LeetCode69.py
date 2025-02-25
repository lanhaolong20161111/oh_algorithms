class Solution:
    def mySqrt(self, x: int) -> int:
        if x==0:return 0
        if x<4:return 1
        low,high=2,x/2
        while low<=high:
            mid=(low+high)//2
            if x/mid<mid:high=mid-1
            elif x/(mid+1)<(mid+1): return int(mid)
            else:low=mid+1
        return 0 
