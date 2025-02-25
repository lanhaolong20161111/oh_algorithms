class Solution:
  def eraseOverlapIntervals(self, intervals: List[List[int]])->int:
    n=len(intervals)
    if n<=1:return 0
    intervals.sort(key=lambda x:x[1])
    ans=1                           #兼容区间的个数，初始为1
    preend=intervals[0][1]           #存放区间0的右端点
    for i in range(1,n):               #遍历intervals
      if intervals[i][0]>=preend:     #当前区间是兼容区间
        ans+=1
        preend=intervals[i][1]
    return n-ans
