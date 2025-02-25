class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        MAXN=10001
        n=len(stones)
        self.Init(2*MAXN)
        for i in range(0,n):
            self.Union(stones[i][0],MAXN+stones[i][1])
        hset=set()        #行号除重
        for i in range(0,n):
            hset.add(stones[i][0])
        ans=0
        for i in hset:
            if self.Find(i)==i: ans+=1
        return n-ans

    def Init(self,n):                             #并查集初始化
        self.parent=[0]*n
        self.rnk=[0]*n
        for i in range(0,n):
            self.parent[i]=i
            self.rnk[i]=0

    def Find(self,x):                        #递归算法：并查集中查找x结点的根结点
        if x!=self.parent[x]:
            self.parent[x]=self.Find(self.parent[x])          #路径压缩
        return self.parent[x]

    def Union(self,x,y):                     #并查集中x和y的两个集合的合并
        rx=self.Find(x)
        ry=self.Find(y)
        if rx==ry:return;                           #x和y属于同一棵树的情况
        if self.rnk[rx]<self.rnk[ry]:
            self.parent[rx]=ry                              #rx结点作为ry的孩子
        else:
            if self.rnk[rx]==self.rnk[ry]:
                self.rnk[rx]+=1                     #秩相同，合并后rx的秩增1
            self.parent[ry]=rx                      #ry结点作为rx的孩子
