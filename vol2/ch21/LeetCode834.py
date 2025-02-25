class Solution:
    def sumOfDistancesInTree(self,n:int,edges:List[List[int]])->List[int]:
        self.answer=[0]*n
        self.cnt=[0]*n
        self.dp=[0]*n
        self.adj=[[] for _ in range(n)]
        for edge in edges:
            a,b=edge[0],edge[1]
            self.adj[a].append(b)
            self.adj[b].append(a)
        self.dfs(0,-1)
        self.dfs2(0,-1)
        return self.answer
    def dfs(self,root,pre):   #树型DP求dp和cnt
        self.dp[root]=0
        self.cnt[root]=1
        for v in self.adj[root]:
            if v==pre:continue
            self.dfs(v,root)
            self.dp[root]+=self.dp[v]+self.cnt[v]
            self.cnt[root]+=self.cnt[v]
    def dfs2(self,root,pre):  #换根求answer
        self.answer[root]=self.dp[root]
        for v in self.adj[root]:
            if v==pre:continue
            dpr,dpv=self.dp[root],self.dp[v]
            cntr,cntv=self.cnt[root],self.cnt[v]
            self.dp[root]-=self.dp[v]+self.cnt[v]
            self.cnt[root]-=self.cnt[v]
            self.dp[v]+=self.dp[root]+self.cnt[root]
            self.cnt[v]+=self.cnt[root]
            self.dfs2(v,root)
            self.dp[root],self.dp[v]=dpr,dpv     #恢复
            self.cnt[root],self.cnt[v]=cntr,cntv
