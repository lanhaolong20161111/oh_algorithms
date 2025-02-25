class BIT:                     #树状数组类
    def __init__(self,n):
        self.n=n
        self.tree=[0]*(n+1)					#树状数组为tree[1..n]
    def lowbit(self,x):
        return x&-x
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
class Solution:
    def countRangeSum(self,nums:List[int],lower:int,upper:int)->int:
        n=len(nums)
        presum=[0]*(n+1)            #前缀和数组
        presum[0]=0
        for i in range(1,n+1):
            presum[i]=presum[i-1]+nums[i-1]
        a=[]                        #离散化
        for x in presum:
            a.append(x)
            a.append(x-lower)
            a.append(x-upper)
        hmap={}
        idx=0
        for x in sorted(a):
            if x not in hmap:
                hmap[x]=idx;idx+=1
        ans=0
        bit=BIT(len(hmap))
        for x in presum:
            i,j,k=hmap[x-upper],hmap[x-lower],hmap[x]
            ans+=bit.Sum(j+1)-bit.Sum(i)
            bit.UpdateOne(k+1,1)
        return ans
