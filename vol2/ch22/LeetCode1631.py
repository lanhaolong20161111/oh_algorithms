class Solution:
  def minimumEffortPath(self, heights: List[List[int]]) -> int:
    dx=[0,0,1,-1]                           #水平方向偏移量
    dy=[1,-1,0,0]                           #垂直方向偏移量
    INF=0x3f3f3f3f
    m,n=len(heights),len(heights[0])
    dist=[[INF for _ in range(0,n)] for _ in range(0,m)]
    pqu=[]          							#定义一个优先队列pqu,元素为[length,x,y]
    heapq.heappush(pqu,[0,0,0])      #源点元素进队
    dist[0][0]=0
    while pqu:
      e=heapq.heappop(pqu)        #出队元素e
      length=e[0]
      x,y=e[1],e[2]
      if x==m-1 and y==n-1:         #找到终点返回
        return length
      for di in range(0,4):					#扩展
        nx,ny=x+dx[di],y+dy[di]
        if nx<0 or nx>=m or ny<0 or ny>=n:continue
        curlen=max(length,abs(heights[nx][ny]-heights[x][y]))
        if curlen<dist[nx][ny]:   #剪支：当前路径长度更短
          dist[nx][ny]=curlen
          heapq.heappush(pqu,[dist[nx][ny],nx,ny]) #(nx,ny进队
    return -1
