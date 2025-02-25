class SegTree:             #线段树类
    def __init__(self,a):
        n=len(a)
        self.a=a
        self.ST=[0]*(4*n)
        self.Create(1,1,n)
    def Create(self,root,L,R):
        if L==R:self.ST[root]=self.a[L-1]
        else:
            mid=(L+R)>>1
            self.Create(2*root,L,mid)
            self.Create(2*root+1,mid+1,R)
            self.ST[root]=self.ST[2*root]+self.ST[2*root+1]
    def UpdateOne(self,root,L,R,i,x):          #单点修改:a[i]+=x
        if L==R:self.ST[root]=x                                            #单点
        else:                                          #非单点
            mid=(L+R)>>1
            if i<=mid:self.UpdateOne(2*root,L,mid,i,x);	     #在左子树中修改
            else: self.UpdateOne(2*root+1,mid+1,R,i,x); #在右子树中修改
            self.ST[root]=self.ST[2*root]+self.ST[2*root+1];       #向上更新分支结点值
    def QueryRange(self,root,L,R,i,j):          #查询区间[i,j]
        if L>=i and R<=j:return self.ST[root]        #当前结点[L,R]包含在[i,j]中
        else:
            mid=(L+R)>>1                           #其他情况
            lsum,rsum=0,0
            if i<=mid:                                      #若[i,j]与左孩子有交集
                lsum=self.QueryRange(2*root,L,mid,i,j)
            if mid<j:                                           #若[i,j]与右孩子有交集
                rsum=self.QueryRange(2*root+1,mid+1,R,i,j)
            return lsum+rsum;
class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        self.m,self.n=len(matrix),len(matrix[0])
        a=[]
        for i in range(0,self.m):
            for j in range(0,self.n):
                a.append(matrix[i][j])
        self.st=SegTree(a)
    def pno(self,i,j):      #二维转换为一维
        return i*self.n+j+1
    def update(self,r:int,c:int,val: int) -> None:
        i=self.pno(r,c)
        self.st.UpdateOne(1,1,self.m*self.n,i,val)
    def sumRegion(self,r1:int,c1:int,r2:int,c2:int) -> int:
        ans=0
        for i in range(r1,r2+1):
            ans+=self.st.QueryRange(1,1,self.m*self.n,self.pno(i,c1),self.pno(i,c2))
        return ans
