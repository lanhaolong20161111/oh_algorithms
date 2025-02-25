class Solution:
    def longestIncreasingPath(self, matrix):
        dx=[0,0,1,-1]       #水平方向偏移量
        dy=[1,-1,0,0]       #垂直方向偏移量
        m,n=len(matrix),len(matrix[0])
        dp=[[1 for _ in range(n)] for _ in range(m)]
        sa=[]
        for i in range(0,m):
            for j in range(0,n):
                sa.append([matrix[i][j],i,j])
        sa.sort(key=lambda x:x[0])
        ans=1;                              #至少为1
        for i in range(0,m*n):
            x,y=sa[i][1],sa[i][2]
            for di in range(0,4):
                nx,ny=x+dx[di],y+dy[di]
                if nx<0 or nx>=m or ny<0 or ny>=n:continue
                if matrix[nx][ny]<=matrix[x][y]:continue
                if dp[nx][ny]>dp[x][y]:continue
                dp[nx][ny]=dp[x][y]+1
                ans=max(ans,dp[nx][ny])
        return ans
