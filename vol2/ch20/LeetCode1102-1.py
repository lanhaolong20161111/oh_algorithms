class Solution:
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        dx=[0,0,1,-1]                       #水平方向偏移量
        dy=[1,-1,0,0]                   	#垂直方向偏移量
        m,n=len(grid),len(grid[0])
        dist=[[-1 for _ in range(0,n)] for _ in range(0,m)]
        qu=deque()               #定义一个队列,元素为[x,y,length]
        qu.append([0,0,grid[0][0]])      #源点元素进队
        dist[0][0]=grid[0][0]
        ans=0
        while qu:
            [x,y,length]=qu.popleft()       #出队元素
            if x==m-1 and y==n-1:ans=max(ans,length)
            for di in range(0,4):
                nx,ny=x+dx[di],y+dy[di]
                if nx<0 or nx>=m or ny<0 or ny>=n:continue
                curlength=min(dist[x][y],grid[nx][ny])
                if curlength>dist[nx][ny]:			#剪支1
                    dist[nx][ny]=curlength
                    if dist[nx][ny]>ans:            #剪支2
                        qu.append([nx,ny,dist[nx][ny]])
        return ans
