class BIT:                     #树状数组类    与上一题完全相同
    def __init__(self,n):
        self.n=n
        self.tree=[0]*(n+1)                 #树状数组为tree[1..n]
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
    def countSmaller(self, nums: List[int]) -> List[int]:
        n=len(nums)
        hmap,idx={},1                   #离散化，序号从1开始
        for x in sorted(nums):
            if x not in hmap:
                hmap[x]=idx;idx+=1
        bit=BIT(idx)
        ans=[0]*n						#存放答案
        for j in range(n-1,-1,-1):
            i=hmap[nums[j]]
            bit.UpdateOne(i,1)
            if i!=1:ans[j]=bit.Sum(i-1)
            else: ans[j]=0
        return ans
