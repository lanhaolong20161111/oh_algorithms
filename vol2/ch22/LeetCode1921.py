class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        n=len(dist)
        times=[0]*n
        for i in range(0,n):
            times[i]=(dist[i]-1)//speed[i]+1
        times.sort()
        ans=0                   #最多消灭的怪物个数
        for i in range(0,n):
            if times[i]>i:ans+=1
            else:return ans
        return n
