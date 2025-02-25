class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        self.dx=[0,0,1,-1]                   #水平方向偏移量
        self.dy=[1,-1,0,0]                   #垂直方向偏移量
        self.qu=deque()                             #定义一个队列qu
        n=len(grid)
        self.visited=[[False for _ in range(0,n)] for _ in range(0,n)]
        find=False
        x,y=-1,-1
        for i in range(0,n):      #找到任意一个陆地(x,y)
            for j in range(0,n):
                if grid[i][j]==1 and not find:
                    find=True
                    x,y=i,j
                    break
            if find:break
        self.dfs(grid,x,y)
        return self.bfs(grid)
    def dfs(self,grid,x,y):         #DFS算法
        self.visited[x][y]=True
        if grid[x][y]==1:             #(x,y)为陆地时进队
            self.qu.append([x,y])
            for di in range(0,4):
                nx,ny=x+self.dx[di],y+self.dy[di]
                if nx<0 or nx>=len(grid) or ny<0 or ny>=len(grid[0]):
                    continue
                if self.visited[nx][ny] or grid[nx][ny]==0:
                    continue
                self.dfs(grid,nx,ny)
    def bfs(self,grid):                 #分层次的BFS
        ans=0
        while self.qu:
            cnt=len(self.qu)                          #求队列中元素个数cnt
            for i in range(0,cnt):              #处理一层的元素
                [x,y]=self.qu.popleft()       #出队[x,y]
                for di in range(0,4):
                    nx,ny=x+self.dx[di],y+self.dy[di]
                    if nx<0 or nx>=len(grid) or ny<0 or ny>=len(grid[0]):
                        continue
                    if self.visited[nx][ny]:continue
                    if grid[nx][ny]==1:return ans
                    self.qu.append([nx,ny])         #(nx,ny)进队
                    self.visited[nx][ny]=True
            ans+=1
        return ans
