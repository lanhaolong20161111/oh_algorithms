class Solution:
  def shortestPath(self, grid: List[List[int]], k: int) -> int:
    INF=0x3f3f3f3f
    dx=[0,0,1,-1]                       #水平方向偏移量
    dy=[1,-1,0,0]                      #垂直方向偏移量
    m,n=len(grid),len(grid[0])       #行列数
    if k>=m+n-2:return m+n-2
    cnt=[[INF for _ in range(0,n)] for _ in range(0,m)]
    cnt[0][0]=0
    pqu=[]          #小根堆pqu,结点为[length,x,y,nums]
    heapq.heappush(pqu,[0,0,0,0])      #源点进队
    ans=INF
    while pqu:
      e=heapq.heappop(pqu)        #出队e
      length,x,y,nums=e[0],e[1],e[2],e[3]
      if x==m-1 and y==n-1:              #找到目标
        ans=min(ans,length)        #求最短路径长度
      for di in range(0,4):          #四周搜索
        nx,ny=x+dx[di],y+dy[di]      #di方位位置为(nx,ny)
        if nx<0 or nx>=m or ny<0 or ny>=n:continue
        nnums=nums+grid[nx][ny]      #新位置遇到的障碍物个数
        if nnums>k:continue             #剪支1
        if nnums>=cnt[nx][ny]:continue  #剪支2
        if length+1<ans:              #剪支3
          cnt[nx][ny]=nnums
          heapq.heappush(pqu,[length+1,nx,ny,nnums])
    if ans==INF:return -1
    return ans
