class Solution:
  def merge(self, intervals: List[List[int]]) -> List[List[int]]:
    n=len(intervals)
    if n<=1:return intervals
    intervals.sort(key=lambda x:x[0])   #按左端点递增排序
    ans=[]
    ans.append(intervals[0])
    for i in range(1,n):    #用i遍历intervals
      curs=intervals[i][0]      #求当前区间[curs,cure)
      cure=intervals[i][1]
      if ans[-1][1]<curs:     #不相交
        ans.append([curs,cure])
      else:                 #相交：合并
        ans[-1][1]=max(ans[-1][1],cure)
    return ans
