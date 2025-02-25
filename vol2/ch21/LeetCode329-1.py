class Solution:
    def longestIncreasingPath(self, matrix):
        self.dx=[0,0,1,-1]       #水平方向偏移量
        self.dy=[1,-1,0,0]       #垂直方向偏移量
        m,n=len(matrix),len(matrix[0])
        self.dp=[[0 for _ in range(n)] for _ in range(m)]
        maxans=0
        for i in range(0,m):
            for j in range(0,n):
                tmp=self.dfs(matrix,m,n,i,j)
                if tmp>maxans:maxans=tmp
        return maxans
    def dfs(self,matrix,m,n,x,y):
        if self.dp[x][y]!=0:return self.dp[x][y]
        self.dp[x][y]=1
        maxlen=0
        for di in range(0,4):
            nx,ny=x+self.dx[di],y+self.dy[di]
            if nx<0 or nx>=m or ny<0 or ny>=n:continue
            if matrix[nx][ny]<=matrix[x][y]:continue
            tmp=self.dfs(matrix,m,n,nx,ny)
            if tmp>maxlen:maxlen=tmp
        self.dp[x][y]+=maxlen
        return self.dp[x][y]
