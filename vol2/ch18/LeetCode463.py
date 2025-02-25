class Solution:
    def islandPerimeter(self,grid:List[List[int]])->int:
        self.dx=[0,0,1,-1]           #水平方向偏移量
        self.dy=[1,-1,0,0]           #垂直方向偏移量
        self.m,self.n=len(grid),len(grid[0])
        self.visited=[[False for _ in range(self.n)] for _ in range(self.m)]
        self.ans=0                  #存放答案
        for i in range(0,self.m):
            for j in range(0,self.n):
                if grid[i][j]==1:       #只有一个陆地
                    self.dfs(grid,i,j)
                    return self.ans
        return 0
    def dfs(self,grid,x,y):
        if self.visited[x][y]:return
        self.visited[x][y]=True
        for di in range(0,4):
            nx,ny=x+self.dx[di],y+self.dy[di]
            if nx<0 or nx>=self.m or ny<0 or ny>=self.n:
                self.ans+=1
            elif grid[nx][ny]==0:
                self.ans+=1
            else:self.dfs(grid,nx,ny)
