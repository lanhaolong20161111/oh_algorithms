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
        pqu=[]                     #定义小根堆pqu,元素为[length,vno]
        heapq.heappush(pqu,[0,node1])      #源点元素进队
        while pqu:                   #队列不空循环
            [length,u]=heapq.heappop(pqu)       #出队
            if u==node2:return dist[u]    #找到目标 
            for edj in self.adj[u]:
                v,w=edj[0],edj[1]            #相邻顶点为v
                if dist[u]+w<dist[v]:    #边松驰:u到v有边且路径长度更短
                    dist[v]=dist[u]+w
                    heapq.heappush(pqu,[dist[v],v])  #顶点v进队
        return -1

