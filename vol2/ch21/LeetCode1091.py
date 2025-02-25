class QNode:                #优先队列结点类型
  x,y=0,0
  f,g,h=0,0,0
  def __lt__(self,other):   #用于按f越小越优先出队
    if self.f<other.f:return True
    else:return False
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        dx=[0,0,-1,1,-1,1,-1,1]
        dy=[-1,1,0,0,-1,-1,1,1]
        n=len(grid)
        if grid[0][0] or grid[n-1][n-1]:return -1
        if n==1:return 1
        visited=[[False for _ in range(0,n)] for _ in range(0,n)]
        pqu=[]
        e=QNode()
        e.x,e.y=0,0
        e.g,e.h=1,self.geth(0,0,n-1,n-1)
        e.f=e.g+e.h
        heapq.heappush(pqu,e)
        visited[0][0]=True
        while pqu:
            e=heapq.heappop(pqu)
            x,y=e.x,e.y
            if x==n-1 and y==n-1:return e.g
            for di in range(0,8):
                nx,ny=x+dx[di],y+dy[di]
                if nx>=0 and nx<n and ny>=0 and ny<n and grid[nx][ny]==0:
                    if visited[nx][ny]:continue
                    e1=QNode()
                    e1.x,e1.y=nx,ny
                    e1.g=e.g+1
                    e1.h=self.geth(nx,ny,n-1,n-1)
                    e1.f=e1.g+e1.h
                    heapq.heappush(pqu,e1)
                    visited[nx][ny]=True
        return -1
    def  geth(self,x,y,gx,gy):      #计算启发式函数值
           return 0.4*(max(abs(gx-x),abs(gy-y)))