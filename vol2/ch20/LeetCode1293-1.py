class Solution:
  def shortestPath(self, grid: List[List[int]], k: int) -> int:
    INF=0x3f3f3f3f
    dx=[0,0,1,-1]                       #水平方向偏移量
    dy=[1,-1,0,0]                      #垂直方向偏移量
    m,n=len(grid),len(grid[0])       #行列数
    if k>=m+n-2:return m+n-2
    cnt=[[INF for _ in range(0,n)] for _ in range(0,m)]
    qu=deque()    #定义一个队列，元素为[x,y,length,nums]
    qu.append([0,0,0,0])        #源点进队
    cnt[0][0]=0
    ans=INF
    while qu:                #队不空循环
      [x,y,length,nums]=qu.popleft()    #出队
      if x==m-1 and y==n-1:              #找到目标
        return length                    #求最小路径
      for di in range(0,4):          #四周搜索
        nx,ny=x+dx[di],y+dy[di]      #di方位位置为(nx,ny)
        if nx<0 or nx>=m or ny<0 or ny>=n:continue
        nnums=nums+grid[nx][ny]      #新位置遇到的障碍物个数
        if nnums>k:continue             #剪支1
        if nnums>=cnt[nx][ny]:continue  #剪支2
        cnt[nx][ny]=nnums
        qu.append([nx,ny,length+1,cnt[nx][ny]])
    return -1
