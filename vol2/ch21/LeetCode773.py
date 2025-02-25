class QNode:                #优先队列结点类型
  x,y=0,0
  grid=""
  f,g,h=0,0,0
  def __lt__(self,other):   #用于按f越小越优先出队
    if self.f<other.f:return True
    else:return False
class Solution:
  dx=[0,0,1,-1]                      #水平方向偏移量
  dy=[1,-1,0,0]                      #垂直方向偏移量
  goal="123450"
  def slidingPuzzle(self, board: List[List[int]]) -> int:
    m,n=2,3
    s="" 
    x,y=-1,-1
    for i in range(0,m):              #将board转换为str并找到0的位置
      for j in range(0,n):
        s+=str(board[i][j])
        if board[i][j]==0:x,y=i,j
    if s==self.goal:return 0
    visited=set()
    pqu=[]      #优先队列，结点为QNode
    e=QNode()
    e.x,e.y=x,y
    e.grid=s
    e.g,e.h=0,self.geth(s)              #或者e.h=0
    e.f=e.g+e.h
    heapq.heappush(pqu,e)               #初始状态进队
    visited.add(e.grid)                 #标记初始状态已访问
    while pqu:
      e=heapq.heappop(pqu)            #出队e
      x,y,s=e.x,e.y,e.grid
      p0=x*n+y
      for di in range(0,4):
        nx,ny=x+self.dx[di],y+self.dy[di]
        if nx<0 or nx>=m or ny<0 or ny>=n:continue
        p1=nx*n+ny
        s1=self.swap(s,p0,p1)     #交换s[p0]和s[p1]得到s1
        if s1==self.goal:return e.g+1   #找到目标
        if s1 in visited:continue   #跳过重复状态
        visited.add(s1)
        e1=QNode()
        e1.x,e1.y,e1.grid=nx,ny,s1
        e1.g=e.g+1
        e1.h=self.geth(s1)
        e1.f=e1.g+e1.h
        heapq.heappush(pqu,e1)
    return -1         #没有找到返回-1

  def swap(self,s,i,j):         #交换s[i]和s[j]
    tmp=list(s)
    tmp[i],tmp[j]=tmp[j],tmp[i]
    return ''.join(tmp)
  def geth(self,s):                 #计算启发式函数值
    h=0
    for i in range(0,6):
      if s[i]!='0' and self.goal[i]!=s[i]:h+=1
    return h
