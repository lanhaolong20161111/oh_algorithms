class NumArray:
    def __init__(self, nums: List[int]):
        MAXN=10010
        self.ST=[None]*(4*MAXN)                  #存放线段树中结点的a值
        self.a=nums
        n=len(nums)
        self.Create(0,0,n-1)
    def sumRange(self,i:int,j: int) -> int:
        return self.QueryRange(0,0,len(self.a)-1,i,j)
    def Create(self,root,L,R):     #创建线段树
        if L==R:                                #叶子结点
            self.ST[root]=self.a[L]
        else:
            mid=(L+R)//2
            self.Create(2*root+1,L,mid)             #递归构造左子树
            self.Create(2*root+2,mid+1,R)               #递归构造右子树
            self.ST[root]=self.ST[2*root+1]+self.ST[2*root+2]     #向上更新
    def QueryRange(self,root,L,R,i,j):   #区间查询
        if L>=i and R<=j:  return self.ST[root]                        #当前结点区间[L,R]包含在[i,j]中
        else:
            mid=(L+R)//2                        #其他情况 
            sum=0;
            if i<=mid:                          #若[i,j]与左孩子有交集
                sum+=self.QueryRange(2*root+1,L,mid,i,j);
            if j>=mid+1:                        #若[i,j]与右孩子有交集
                sum+=self.QueryRange(2*root+2,mid+1,R,i,j)
            return sum