#from collections import defaultdict, deque
#from typing import DefaultDict, List, Set
class Solution:
    def distanceToCycle(self,n:int,edges:List[List[int]])->List[int]:
        self.adj=defaultdict(set)
        for u,v in edges:								#创建邻接表adj
            self.adj[u].add(v)
            self.adj[v].add(u)
        cycle=self.findCycle(n)
        ans=[n+1]*n
        for i in cycle:
            ans[i]=0
        qu=deque([i for i in cycle])    #环中全部顶点进队
        dist=0
        while qu:                   #队不空循环
            cnt=len(qu)
            for i in range(0,cnt):
                cur=qu.popleft()
                for next in self.adj[cur]:
                    if ans[next]>dist+1:
                        ans[next]=dist+1
                        qu.append(next)
            dist+=1
        return ans

    def dfs(self,u:int,pre:int)->bool:   #环检测，并记录路径
        if self.visited[u]:return True
        self.visited[u]=True
        for v in self.adj[u]:       #存在(u,v)边
            if v==pre:continue      #跳过(u,v,u)的环
            self.path.append(v)
            if self.dfs(v,u):return True
            self.path.pop()         #回溯
        return False
    def findCycle(self,n:int)->List[int]:
        cycle=[]                    #存放环上的顶点
        self.path=[]
        self.visited=[False]*n
        for i in range(n):
            if self.visited[i]:continue
            self.path.append(i)
            if self.dfs(i,-1):break
        last=self.path.pop()
        cycle.append(last)
        while self.path and self.path[-1]!=last:
            cycle.append(self.path.pop())
        return cycle
