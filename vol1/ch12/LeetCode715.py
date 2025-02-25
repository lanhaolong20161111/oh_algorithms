class SNode:                                #线段树结点类
    def __init__(self):
        self.val=0              #结点值
        self.flag=0             #懒标记
        self.left,self.right=-1,-1     #左右孩子指针

class RangeModule:
    MAXN=1000000005
    def __init__(self):
        self.ST=[]               #用列表存放线段树，下标从0开始
        self.ST.append(SNode());       #在线段树中添加根结点ST[0]
    def UpdateRange(self,root,L,R,i,j,x):    #区间修改
        m=R-L+1;          #区间长度
        if i<=L and R<=j:
            if x==1:self.ST[root].val=m
            else:self.ST[root].val=0
            self.ST[root].flag=x
        else:
            self.PushDown(root,m)
            mid=(L+R)>>1
            if i<=mid:self.UpdateRange(self.ST[root].left,L,mid,i,j,x)
            if j>mid:self.UpdateRange(self.ST[root].right,mid+1,R,i,j,x)
            self.ST[root].val=self.ST[self.ST[root].left].val+self.ST[self.ST[root].right].val
    def QueryRange(self,root,L,R,i,j):  #区间查询
        if i<=L and R<=j:return self.ST[root].val
        else:
            self.PushDown(root,R-L+1)
            mid=(L+R)>>1
            ans=0
            if i<=mid:ans=self.QueryRange(self.ST[root].left,L,mid,i,j);
            if j>mid: ans+=self.QueryRange(self.ST[root].right,mid+1,R,i,j)
            return ans
    def PushDown(self,root,m):            #向下传递算法
        if self.ST[root].left==-1:         #动态开点:创建左孩子
            self.ST.append(SNode())
            self.ST[root].left=len(self.ST)-1
        if self.ST[root].right==-1:        #动态开点:创建右孩子
            self.ST.append(SNode())
            self.ST[root].right=len(self.ST)-1
        if self.ST[root].flag==0: return
        if self.ST[root].flag==-1:
            self.ST[self.ST[root].left].val=self.ST[self.ST[root].right].val=0
        else:
            self.ST[self.ST[root].left].val=m-m//2
            self.ST[self.ST[root].right].val=m//2
        self.ST[self.ST[root].left].flag=self.ST[self.ST[root].right].flag=self.ST[root].flag
        self.ST[root].flag=0
    def addRange(self, left: int, right: int) -> None:
        self.UpdateRange(0,0,self.MAXN-1,left,right-1,1)
    def queryRange(self, left: int, right: int) -> bool:
        return self.QueryRange(0,0,self.MAXN-1,left,right-1)==right-left;
    def removeRange(self, left: int, right: int) -> None:
        self.UpdateRange(0,0,self.MAXN-1,left,right-1,-1);
