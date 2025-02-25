class SNode:
    def __init__(self):
        self.val=0
        self.left,self.right=-1,-1
class Solution:
    def __init__(self):
        self.INF=0x3f3f3f3f3f
        self.ST=[]                          #用列表存放线段树，下标从0开始
        self.ST.append(SNode())                         #在ST中添加根结点ST[0]

    def UpdateOne(self,root,L,R,i):
        cnode=self.ST[root]
        if L==R:cnode.val+=1
        else:
            if cnode.left==-1:                          #创建左孩子，其下标为n-1
                self.ST.append(SNode())
                cnode.left=len(self.ST)-1
            if cnode.right==-1:
                self.ST.append(SNode())                 #创建右孩子，其下标为n-1
                cnode.right=len(self.ST)-1
            mid=(L+R)>>1
            if i<=mid:self.UpdateOne(cnode.left,L,mid,i)
            else:self.UpdateOne(cnode.right,mid+1,R,i)
            cnode.val=self.ST[cnode.left].val+self.ST[cnode.right].val
    def QueryRange(self,root,L,R,i,j):
        if root==-1:return 0    #查询到空结点返回0
        if j<L or i>R: return 0
        cnode=self.ST[root]
        if i<=L and j>=R:return cnode.val
        else:
            mid=(L+R)>>1
            lans=self.QueryRange(cnode.left,L,mid,i,j)
			rans=self.QueryRange(cnode.right,mid+1,R,i,j)
		return lans+rans
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        n=len(nums)
        presum=[0]*(n+1)         #前缀和数组
        presum[0]=0
        for i in range(1,n+1):
            presum[i]=presum[i-1]+nums[i-1]
        minv,maxv=self.INF,-self.INF
        for x in presum:                            #求最大区间[minv,maxv]
            minv=min(minv,x,x-lower,x-upper)
            maxv=max(maxv,x,x-lower,x-upper)
        ans=0
        for x in presum:
            i,j=x-upper,x-lower
            ans+=self.QueryRange(0,minv,maxv,i,j)   #线段树的根结点为ST[0]
            self.UpdateOne(0,minv,maxv,x)
        return ans
