class Solution:
  def jump(self, nums: List[int]) -> int:
    INF=0x3f3f3f3f
    n=len(nums)
    if n==1:return 0
    i,steps=0,0
    while i<n-1:
      end=i+nums[i]
      if end>=n-1:    #从位置i可以跳到终点
        steps+=1
        break
      maxj=i+1
      for j in range(i+2,end+1):  #求maxj={j|j+nums[j]最大，j属于[i+1,end]
        if j+nums[j]>maxj+nums[maxj]:maxj=j
      i,steps=maxj,steps+1    #从位置i跳到位置maxj
    return steps
