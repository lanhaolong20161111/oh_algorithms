class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n=len(graph)
        revadj=[[] for _ in range(n)]   #反图邻接表
        degree=[0]*n                    #存放反图的入度
        ans=set()
        qu=deque()                      #对反图进行拓扑排序(队列型)
        for i in range(n):
            degree[i]=len(graph[i])
            if degree[i]==0:qu.append(i)
            for j in graph[i]:
                revadj[j].append(i)
        while qu:
            cnt=len(qu)
            for i in range(0,cnt):
                u=qu.popleft()
                ans.add(u)
                for v in revadj[u]:
                    degree[v]-=1
                    if degree[v]==0:qu.append(v)  
        return sorted(list(ans))
