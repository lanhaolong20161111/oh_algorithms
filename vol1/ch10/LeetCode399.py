class Solution:
    def calcEquation(self,equations:List[List[str]],values:List[float],queries:List[List[str]]) -> List[float]:
        m,n=len(queries),len(equations)
        self.Init(2*n)
        id=0                           #给不同变量从0开始编号
        hmap={}
        for i in range(0,n):
            if equations[i][0] not in hmap:
                hmap[equations[i][0]]=id;id+=1
            if equations[i][1] not in hmap:
                hmap[equations[i][1]]=id;id+=1
            x=hmap[equations[i][0]]
            y=hmap[equations[i][1]]
            self.Union(x,y,values[i])
        ans=[None]*m;              #存放答案
        for i in range(0,m):
            if queries[i][0] not in hmap or queries[i][1] not in hmap:
                ans[i]=-1.0
                continue
            x=hmap[queries[i][0]]
            y=hmap[queries[i][1]]
            rx=self.Find(x)
            ry=self.Find(y)
            if rx==ry: ans[i]=self.weight[x]/self.weight[y]
            else: ans[i]=-1.0
        return ans

    def Init(self,n):
        self.parent=[None]*n;
        self.weight=[None]*n;
        for i in range(0,n):
            self.parent[i]=i
            self.weight[i]=1.0

    def Find(self,x):
        if x!=self.parent[x]:
            origin=self.parent[x]
            self.parent[x]=self.Find(self.parent[x])
            self.weight[x]*=self.weight[origin]
        return self.parent[x]

    def Union(self,x,y,val):
        rx=self.Find(x)
        ry=self.Find(y)
        if rx==ry:return
        self.parent[rx]=ry
        self.weight[rx]=val*self.weight[y]/self.weight[x]
