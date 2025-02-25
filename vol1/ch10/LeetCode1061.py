class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        self.Init(26)
        for i in range(0,len(s1)):
            x=ord(s1[i])-ord('a')
            y=ord(s2[i])-ord('a')
            self.Union(x,y)
        ans=""
        for i in range(0,len(baseStr)):
            x=ord(baseStr[i])-ord('a')
            rx=self.Find(x)
            ans+=chr(rx+ord('a'))
        return ans

    def Init(self,n):                             #并查集初始化
        self.parent=[0]*n         #并查集存储结构
        for i in range(0,n):
            self.parent[i]=i

    def Find(self,x):                        #递归算法：并查集中查找x结点的根结点
        if x!=self.parent[x]:
            self.parent[x]=self.Find(self.parent[x])          #路径压缩
        return self.parent[x]

    def Union(self,x,y):                     #并查集中x和y的两个集合的合并
        rx=self.Find(x)
        ry=self.Find(y)
        if rx==ry:return                         #x和y属于同一棵树的情况
        if rx<ry:self.parent[ry]=rx                 #较小编号的结点作为根
        else: self.parent[rx]=ry
