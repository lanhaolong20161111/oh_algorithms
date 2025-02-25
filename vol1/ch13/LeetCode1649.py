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
    MOD=1000000007
    def createSortedArray(self,instructions: List[int]) -> int:
        maxv=max(instructions)
        bit=BIT(maxv)
        ans=0
        for j in range(0,len(instructions)):
            i=instructions[j]
            smaller=bit.Sum(i-1)
            larger=j-bit.Sum(i)
            ans+=min(smaller,larger)
            bit.UpdateOne(i,1)
        return ans % self.MOD