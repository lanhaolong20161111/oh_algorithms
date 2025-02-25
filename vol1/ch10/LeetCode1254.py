class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        self.m,self.n=len(grid),len(grid[0])
        if self.m==1 and self.n==1:return 0
        self.grid=grid
        self.ans=0              #存放封闭岛屿的数量
        self.Init()
        for i in range(0,self.m):
            for j in range(0,self.n):
                if self.grid[i][j]==0:
                    if j<self.n-1 and self.grid[i][j+1]==0:
                        self.Union(self.pno(i,j),self.pno(i,j+1))
                    if i<self.m-1 and self.grid[i+1][j]==0:
                        self.Union(self.pno(i,j),self.pno(i+1,j))
        return self.ans

    def pno(self,i,j):       #二维转换为一维
        return i*self.n+j

    def initEdge(self,x):
            self.parent[x]=0
            self.onedge[x]=True

    def Init(self):                             #并查集初始化
        self.parent=[0]*self.m*self.n
        self.rnk=[0]*self.m*self.n
        self.onedge=[False]*self.m*self.n       #边缘是否有水
        for i in range(0,self.m):
            for j in range(0,self.n):
                if self.grid[i][j]==0:
                    k=self.pno(i,j)
                    self.parent[k]=k
                    self.rnk[k]=0
                    self.ans+=1
        for i in range(0,self.m):
            if self.grid[i][0]==0:         #第0列
                self.initEdge(self.pno(i,0))
            if self.grid[i][self.n-1]==0:       #第n-1列
                self.initEdge(self.pno(i,self.n-1))
        for j in range(1,self.n-1):
            if self.grid[0][j]==0:         #第0行
                self.initEdge(self.pno(0,j))
            if self.grid[self.m-1][j]==0:       #第m-1行
                self.initEdge(self.pno(self.m-1,j))

    def Find(self,x):                        #递归算法：并查集中查找x结点的根结点
        if x!=self.parent[x]:
            self.parent[x]=self.Find(self.parent[x])          #路径压缩
        return self.parent[x]

    def Union(self,x,y):                     #并查集中x和y的两个集合的合并
        rx=self.Find(x)
        ry=self.Find(y)
        if rx==ry:return;                           #x和y属于同一棵树的情况
        if self.rnk[rx]<self.rnk[ry]:
            self.parent[rx]=ry                              #rx结点作为ry的孩子
            self.onedge[ry]=self.onedge[ry] | self.onedge[rx]
        else:
            if self.rnk[rx]==self.rnk[ry]:
                self.rnk[rx]+=1                     #秩相同，合并后rx的秩增1
            self.parent[ry]=rx                      #ry结点作为rx的孩子
            self.onedge[rx]=self.onedge[rx] | self.onedge[ry]
        self.ans-=1
