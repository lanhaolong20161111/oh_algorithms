class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        self.dx=[0,0,1,-1]                        #水平方向偏移量
        self.dy=[1,-1,0,0]                       #垂直方向偏移量
        self.m,self.n=len(grid),len(grid[0])
        ans=0
        for i in range(0,self.m):
            for j in range(0,self.n):
                if grid[i][j]=='1':
                    ans+=1                      #累计调用dfs的次数
                    self.bfs(grid,i,j)
        return ans
    def bfs(self,grid,i,j):  #(i,j)位置出发广度优先遍历
        qu=deque()                                  #定义一个队列
        grid[i][j]='0'                                 #访问(i,j)
        qu.append([i,j])                #(i,j)进队
        while len(qu)>0:
            [i,j]=qu.popleft();                 #出队元素[i,j]
            for di in range(0,4):
                x,y=i+self.dx[di],j+self.dy[di]     #求出di方位的位置(x,y)
                if x<0 or x>=self.m or y<0 or y>=self.n: 
                    continue                    #超界时跳过
                if grid[x][y]=='0':
                    continue
                grid[x][y]='0';                 #访问(x,y)
                qu.append([x,y])     #(x,y)进队
