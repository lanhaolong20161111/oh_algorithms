class Solution:
    def findShortestCycle(self, n: int, edges: List[List[int]]) -> int:
        self.INF=0x3f3f3f3f
        self.adj=defaultdict(set)
        for u,v in edges:                               #创建邻接表adj
            self.adj[u].add(v)
            self.adj[v].add(u)
        ans=self.INF
        for u in range(0,n):
            for v in self.adj[u]:
                ans=min(ans,self.bfs(n,u,v)+1)
        return -1 if ans==self.INF else ans
    def bfs(self,n,u,v):
        dist=[self.INF]*n
        qu=deque()
        qu.append(u)
        dist[u]=0
        while qu:
            i=qu.popleft()
            for j in self.adj[i]:
                if dist[j]==self.INF:
                    if i==u and j==v:continue;
                    qu.append(j)
                    dist[j]=dist[i]+1
        return dist[v]
