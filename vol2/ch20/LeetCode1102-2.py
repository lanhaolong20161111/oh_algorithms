class Solution:
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        dx=[0,0,1,-1]                       #水平方向偏移量
        dy=[1,-1,0,0]                   #垂直方向偏移量
        m,n=len(grid),len(grid[0])
        dist=[[-1 for _ in range(0,n)] for _ in range(0,m)]
        pqu=[]                          #定义大根堆pqu,元素为[-length,x,y]
        heapq.heappush(pqu,[-grid[0][0],0,0])      #源点元素进队
        dist[0][0]=grid[0][0]
        ans=0
        while pqu:
            e=heapq.heappop(pqu)        #出队元素e
            length,x,y=e[0],e[1],e[2]
            length=-length              #恢复正值
            if x==m-1 and y==n-1:ans=max(ans,length)
            for di in range(0,4):
                nx,ny=x+dx[di],y+dy[di]
                if nx<0 or nx>=m or ny<0 or ny>=n:continue
                curlength=min(dist[x][y],grid[nx][ny])
                if curlength>dist[nx][ny]:
                    dist[nx][ny]=curlength
                    heapq.heappush(pqu,[-dist[nx][ny],nx,ny])
        return ans
