class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        INF=0x3f3f3f3f
        n=len(graph)
        self.A=[[INF for _ in range(n)] for _ in range(n)]
        for i in range(0,n):    #建立邻接矩阵A
            for j in graph[i]:self.A[i][j]=1
        self.Floyd()
        m=1<<n;           #总的状态数
        dp=[[INF for _ in range(n)] for _ in range(m)]
        for i in range(0,n):dp[1<<i][i]=0
        for state in range(0,m):     #枚举所有的state
            for i in range(0,n):    #枚举state中已访问的i
                if not self.inset(state,i):continue;  #i不在state中时跳过
                for j in range(0,n):    #枚举state中尚未访问过的j
                    if self.inset(state,j):continue  #j在state中时跳过
                    state1=self.addj(state,j)
                    dp[state1][j]=min(dp[state1][j],dp[state][i]+self.A[i][j])
        return min(dp[m-1])
    def inset(self,state,j):       #判断顶点j是否在state中
        return (state & (1<<j))!=0
    def addj(self,state,j):       #在state添加顶点j
        return state | (1<<j)
    def Floyd(self):
        n=len(self.A)
        for k in range(0,n):
            for i in range(0,n):
                for j in range(0,n):
                    self.A[i][j]=min(self.A[i][j],self.A[i][k]+self.A[k][j])
