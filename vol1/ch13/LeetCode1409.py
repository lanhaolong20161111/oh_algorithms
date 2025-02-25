class SNode:                                #线段树结点类
    def __init__(self):
        self.val=0        #原数
        self.add=0        #增数add数
        self.mul=1        #倍数mul数
        self.left,self.right=-1,-1     #左右孩子指针
class Fancy:
    MAXN=100005
    MOD=1000000007
    def __init__(self):
        self.ST=[]               #用列表存放线段树，下标从0开始
        self.ST.append(SNode());       #在线段树中添加根结点ST[0]
        self.end=0                      #添加元素的位置（添加的元素个数）

    def PushDown(self,root):           #向下传递算法
        cnode=self.ST[root]
        if self.ST[root].left==-1:         #动态开点:创建左孩子
            self.ST.append(SNode())
            cnode.left=len(self.ST)-1
        if cnode.right==-1:        #动态开点:创建右孩子
            self.ST.append(SNode())
            cnode.right=len(self.ST)-1
        lnode,rnode=self.ST[cnode.left],self.ST[cnode.right]
        if cnode.add==0 and cnode.mul==1:return
        lnode.mul=(cnode.mul*lnode.mul)%self.MOD
        rnode.mul=(cnode.mul*rnode.mul)%self.MOD
        lnode.add=(cnode.mul*lnode.add)%self.MOD
        rnode.add=(cnode.mul*rnode.add)%self.MOD
        cnode.mul=1
        lnode.add=(cnode.add+lnode.add)%self.MOD
        rnode.add=(cnode.add+rnode.add)%self.MOD
        cnode.add=0

    def addRange(self,root,L,R,i,j,val):
        if i>j: return
        if i<=L and R<=j:
            self.ST[root].add=(self.ST[root].add+val)%self.MOD
        else:
            self.PushDown(root)
            mid=(L+R)//2
            if i<=mid:self.addRange(self.ST[root].left,L,mid,i,j,val)
            if j>mid:self.addRange(self.ST[root].right,mid+1,R,i,j,val)

    def mulRange(self,root,L,R,i,j,val):
        if i>j: return
        if i<=L and R<=j:
            self.ST[root].add=(self.ST[root].add*val)%self.MOD
            self.ST[root].mul=(self.ST[root].mul*val)%self.MOD
        else:
            self.PushDown(root)
            mid=(L+R)//2
            if i<=mid: self.mulRange(self.ST[root].left,L,mid,i,j, val)
            if j>mid: self.mulRange(self.ST[root].right,mid+1,R,i,j,val)

    def Query(self,i):                      #查询
        id=self.QueryOne(0,0,self.MAXN-1,i)            #找到累积，累和的索引
        return (self.ST[i].val*self.ST[id].mul+self.ST[id].add)%self.MOD  #原数*累积+累和

    def QueryOne(self,root,L,R,i):  #单点查询
        if L==R:return root
        else:
            self.PushDown(root)
            mid=(L+R)//2
            if i<=mid: return self.QueryOne(self.ST[root].left,L,mid,i)
            else: return self.QueryOne(self.ST[root].right,mid+1,R,i)

    def append(self, val: int) -> None:
        self.ST.append(SNode())
        self.ST[self.end].val=val
        self.end+=1

    def addAll(self, inc: int) -> None:
        self.addRange(0,0,self.MAXN-1,0,self.end-1,inc);

    def multAll(self, m: int) -> None:
        self.mulRange(0,0,self.MAXN-1,0,self.end-1,m);

    def getIndex(self, idx: int) -> int:
        if idx>=self.end:return -1
        return self.Query(idx)
