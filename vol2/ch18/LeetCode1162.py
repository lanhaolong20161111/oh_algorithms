class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        self.dx=[0,0,1,-1]                     #水平方向偏移量
        self.dy=[1,-1,0,0]                      #垂直方向偏移量
        self.qu=deque()
        n=len(grid)
        self.visited=[[False for _ in range(0,n)] for _ in range(0,n)]
        cnt=0
        for i in range(0,n):
            for j in range(0,n):
                if grid[i][j]==1:            #陆地单元
                    self.qu.append([i,j])
                    self.visited[i][j]=True
                    cnt+=1
        if cnt==n*n:return -1     #全部为陆地的情况
        else: return self.bfs(grid)
    def bfs(self,grid):    #多起点分层次广度优先搜索
        n=len(grid)
        step=0
        while self.qu:
            cnt=len(self.qu)
            for i in range(0,cnt):
                [x,y]=self.qu.popleft()
                for di in range(0,4):
                    nx=x+self.dx[di]
                    ny=y+self.dy[di]
                    if nx<0 or nx>=n or ny<0 or ny>=n:
                        continue
                    if self.visited[nx][ny]:continue
                    if grid[nx][ny]==1: continue
                    self.visited[nx][ny]=True
                    self.qu.append([nx,ny])
            step+=1
        return step-1
