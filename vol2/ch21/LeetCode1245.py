class Solution:
    def treeDiameter(self, edges: List[List[int]]) -> int:
        n=len(edges)+1
        self.adj=[[] for _ in range(n)]
        self.dp1,self.dp2=[0]*n,[0]*n
        for edge in edges:
            a,b=edge[0],edge[1]
            self.adj[a].append(b)
            self.adj[b].append(a)
        self.dfs(0,-1)
        ans=0
        for i in range(0,n):
            ans=max(ans,self.dp1[i]+self.dp2[i])
        return ans
    def dfs(self,root,pre):   #树型DP
        for v in self.adj[root]:
            if v==pre:continue
            self.dfs(v,root)
            d=self.dp1[v]+1             #d为root的
            if d>=self.dp1[root]:
                self.dp2[root]=self.dp1[root]
                self.dp1[root]=d
            elif d>self.dp2[root]:
                self.dp2[root]=d
