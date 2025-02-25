class Solution:
  def findMaximizedCapital(self,k:int,w:int,profits:List[int],capital:List[int])->int:
    n=len(capital)
    proj=[]           #项目表
    for i in range(0,n):
      proj.append([capital[i],profits[i]])
    pqu=[]        #大根堆,结点类型为[利润即pro]
    proj.sort(key=lambda x:x[0])    #按启动资本递增排序
    ans=w            #当前的最多资本
    i=0                      #遍历proj
    for j in range(0,k):       #最多取k个项目
      while i<n and proj[i][0]<=ans:
        heapq.heappush(pqu,-proj[i][1]) #将所有满足启动资本要求的进队
        i+=1
      if pqu:     #选择最大利润的项目
        ans+=-heapq.heappop(pqu)            #增加总资本
      else:break
    return ans
