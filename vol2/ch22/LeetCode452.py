class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        n=len(points)
        if n==1:return 1
        points.sort(key=lambda x:x[1])
        ans=0
        preend=points[0][1]
        ans+=1
        for i in range(1,n):
            if points[i][0]>preend:
                ans+=1
                preend=points[i][1]
        return ans
