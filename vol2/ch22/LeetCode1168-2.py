class UFS():                  #并查集类
  def __init__(self,n):
    self.n=n
    self.parent=[0]*self.n                   #并查集存储结构
    self.rnk=[-1]*self.n                    #存储结点的秩(近似于高度)
  def Init(self):                               #并查集初始化
    for i in range(0,self.n):
      self.parent[i]=i
      self.rnk[i]=0
  def Find(self,x):         #递归算法：并查集中查找x结点的根结点
    if x!=self.parent[x]:
      self.parent[x]=self.Find(self.parent[x])        #路径压缩
    return self.parent[x]
  def Union(self,rx,ry):                        #并查集中x和y的两个集合的合并
    if self.rnk[rx]<self.rnk[ry]:
      self.parent[rx]=ry                 #rx结点作为ry的孩子
    else:
      if self.rnk[rx]==self.rnk[ry]:          #秩相同，合并后rx的秩增1
        self.rnk[rx]+=1
      self.parent[ry]=rx                  #ry结点作为rx的孩子

class Solution:
  def minCostToSupplyWater(self, n:int,wells:List[int],pipes:List[List[int]])->int:
    for i in range(1,n+1):     #建立超级源点0
      pipes.append([0,i,wells[i-1]])
    return self.Kruskal(n+1,pipes)
  def Kruskal(self,n,E):         #Kruskal算法
    ufs=UFS(n) 
    E.sort(key=itemgetter(2))           #按边权值递增排序
    ans=0
    ufs.Init()                    #初始化并查集
    k,j=0,0                           #k表示当前构造生成树的边数
    while k<n-1:                        #生成的边数小于n-1时循环
      u1,v1=E[j][0],E[j][1]               #取一条边(u1,v1)
      sn1,sn2=ufs.Find(u1),ufs.Find(v1)   #两个顶点所属的集合编号
      if sn1!=sn2:                        #添加该边不会构成回路
        ans+=E[j][2]      #产生最小生成树的一条边
        k+=1                #生成边数增1
        ufs.Union(sn1,sn2)        #将sn1和sn2两个顶点合并
      j+=1                #遍历下一条边
    return ans
