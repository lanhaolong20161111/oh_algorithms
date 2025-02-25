class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n=len(edges)                                 #n为顶点个数
        self.Init(n)                                #并查集初始化
        for i in range(0,n):
            tmp=edges[i]           #取一条边tmp
            x,y=tmp[0],tmp[1]                  #取一条边的头尾顶点
            rx=self.Find(x)
            ry=self.Find(y)                     #分别得到两个顶点所属连通分量编号
            if rx!=ry:self.parent[rx]=ry     #两棵子树合并，新根为ry
            else: return tmp          #说明有环,返回冗余边tmp
        return []

    def Init(self,n):                              #并查集初始化
        self.parent=[0]*(n+1)
        self.rnk=[0]*(n+1)
        for i in range(1,n+1):
            self.parent[i]=i
            self.rnk[i]=0

    def Find(self,x):                        #递归算法：并查集中查找x结点的根结点
        if x!=self.parent[x]:
            self.parent[x]=self.Find(self.parent[x])          #路径压缩
        return self.parent[x]
