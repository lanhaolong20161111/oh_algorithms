class BIT:                     #树状数组类
    def __init__(self,n):
        self.n=n
        self.tree=[0]*(n+1)
    def lowbit(self,x):
        return x&-x
    def UpdateOne(self,i,x):        #单点修改
        while i<=self.n:
            self.tree[i]+=x
            i+=self.lowbit(i)
    def Sum(self,i):                       #求前缀和
        ans=0
        while i>0:
            ans+=self.tree[i]
            i-=self.lowbit(i)
        return ans

class Solution:
    def kEmptySlots(self, bulbs: List[int], k:int)->int:
        n=len(bulbs)
        open=[False]*(n+1)
        bit=BIT(n)
        for i in range(0,n):
            x=bulbs[i]              #当前位置是x             
            p=x+k+1;            #后面位置是x+k+1
            if p<=n and open[p]:
                if bit.Sum(x+1)==bit.Sum(p):return i+1
            p=x-k-1             #前面位置是x+k+1
            if p>0 and open[p]:
                if bit.Sum(p+1)==bit.Sum(x):return i+1
            bit.UpdateOne(x+1,1)       #第i天打开灯泡
            open[x]=True
        return -1
