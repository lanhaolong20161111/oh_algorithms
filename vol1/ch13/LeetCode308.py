class BIT:                     #树状数组类
    def lowbit(self,x):
        return x&-x
    def Create(self,a):     #由a[0..n-1]创建树状数组
        self.n=len(a)
        self.tree=[0]*(self.n+1)				#树状数组为tree[1..n]
        for i in range(1,self.n+1):
            self.tree[i]+=a[i-1]
            if i+self.lowbit(i)<=self.n:
                self.tree[i+self.lowbit(i)]+=self.tree[i] 
    def UpdateOne(self,i,x):        #单点修改
        while i<=self.n:
            self.tree[i]+=x
            i+=self.lowbit(i)
    def Sum(self,i):            #求前缀和
        ans=0
        while i>0:
            ans+=self.tree[i]
            i-=self.lowbit(i)
        return ans
class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        m,self.n=len(matrix),len(matrix[0])
        a=[]
        for i in range(0,m):
            for j in range(0,self.n):a.append(matrix[i][j])
        self.bit=BIT()
        self.bit.Create(a)
        self.mat=matrix
    def pno(self,i,j):                             #二维转换为一维
        return i*self.n+j+1
    def update(self,r:int,c:int,val:int) -> None:
        i=self.pno(r,c) 
        self.bit.UpdateOne(i,val-self.mat[r][c])
        self.mat[r][c]=val
    def sumRegion(self,r1:int,c1:int,r2:int,c2:int) -> int:
        ans=0
        for  r in range(r1,r2+1):
            i,j=self.pno(r,c1),self.pno(r,c2)
            ans+=self.bit.Sum(j)-self.bit.Sum(i-1)
        return ans
