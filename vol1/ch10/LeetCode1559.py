class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        self.m,self.n=len(grid),len(grid[0])        
        self.Init(self.m*self.n)
        for  i in range(0,self.m):
            for  j in range(0,self.n):
                curv=grid[i][j]
                if j<self.n-1 and grid[i][j+1]==curv:      #grid[i][j+1]为curv
                    if self.Union(self.pno(i,j),self.pno(i,j+1)):
                        return True                     #(i,j)和(i,j+1)合并成功
                if i<self.m-1 and grid[i+1][j]==curv:       #grid[i+1][j]为curv
                    if self.Union(self.pno(i,j),self.pno(i+1,j)): 
                        return True                 #(i,j)和(i+1,j)合并成功
        return False

    def pno(self,i,j):       #二维转换为一维
        return i*self.n+j

    def Init(self,n):                             #并查集初始化
        self.parent=[0]*n
        self.rnk=[0]*n
        for i in range(0,n):
            self.parent[i]=i
            self.rnk[i]=0

    def Find(self,x):                        #递归算法：并查集中查找x结点的根结点
        if x!=self.parent[x]:
            self.parent[x]=self.Find(self.parent[x])          #路径压缩
        return self.parent[x]

    def Union(self,x,y):                     #并查集中x和y的两个集合的合并
        rx=self.Find(x)
        ry=self.Find(y)
        if rx==ry:return True;                           #x和y属于同一棵树的情况
        if self.rnk[rx]<self.rnk[ry]:
            self.parent[rx]=ry                              #rx结点作为ry的孩子
        else:
            if self.rnk[rx]==self.rnk[ry]:
                self.rnk[rx]+=1                     #秩相同，合并后rx的秩增1
            self.parent[ry]=rx                      #ry结点作为rx的孩子
        return False
