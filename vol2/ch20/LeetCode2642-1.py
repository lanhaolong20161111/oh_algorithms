class Graph:
    def __init__(self, n: int, edges: List[List[int]]):
        self.adj=[[] for _ in range(0,n)]                    #邻接表
        for edj in edges:
            self.addEdge(edj)

    def addEdge(self,edge:List[int]) -> None:
        a,b,w=edge[0],edge[1],edge[2]   #<a,b>:w
        self.adj[a].append([b,w])

    def shortestPath(self, node1: int, node2: int) -> int:
        INF=0x3f3f3f3f
        n=len(self.adj)
        dist=[INF for _ in range(n)]   #定义dist并初始化所有元素为INF
        dist[node1]=0
        qu=deque()          #定义一个队列qu,元素类型为(vno)
        qu.append(node1)              #源点进队
        ans=INF                     #存放答案
        while qu:                   #队列不空循环
            u=qu.popleft()             #出队顶点u
            if u==node2:ans=min(ans,dist[u])    #找到目标 
            for edj in self.adj[u]:
                v,w=edj[0],edj[1]            #相邻顶点为v
                if dist[u]+w<dist[v]:    #剪支1：边松驰
                    dist[v]=dist[u]+w
                    if dist[v]<ans:qu.append(v)     #剪分2
        if ans==INF:return -1;
        return ans

