class Solution:
  def minCostConnectPoints(self, points: List[List[int]]) -> int:
    n=len(points)
    if n==1:return 0
    if n==2:return self.dist(points,0,1)
    return self.Prim(points,0)
  def dist(self,points,i,j):  #求曼哈顿距离
    return abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])
  def Prim(self,points,v):        #Prim算法
    INF=0x3f3f3f3f
    n=len(points)
    lowcost,closest=[0]*n,[0]*n
    ans=0
    for i in range(0,n):  #给lowcost[]和closest[]置初值
      lowcost[i]=self.dist(points,v,i)
      closest[i]=v
    for i in range(1,n):  #找出(n-1)个顶点
      mind,k=INF,-1
      for j in range(0,n):  #在(V-U)中找出离U最近的顶点k
        if lowcost[j]!=0 and lowcost[j]<mind:
          mind=lowcost[j]
          k=j              #k记录当前最小边的顶点
      ans+=mind           #生成最小生成树的一条边
      lowcost[k]=0         #标记k已经加入U
      for j in range(0,n):     #对(V-U)中顶点j进行调整
        if lowcost[j]!=0 and self.dist(points,k,j)<lowcost[j]:
          lowcost[j]=self.dist(points,k,j)
          closest[j]=k      #修改数组lowcost和closest
    return ans
