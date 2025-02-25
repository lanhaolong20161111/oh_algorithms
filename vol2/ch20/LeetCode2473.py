class Solution:
    def minCost(self,n:int,roads:List[List[int]],appleCost:List[int],k:int):
        INF=0x3f3f3f3f3f3f3f3f
        adj=[[] for _ in range(0,n+1)]                    #邻接表
        for i in range(0,len(roads)):      #遍历roads建立邻接表
            a,b=roads[i][0],roads[i][1]     #<a,b>:w
            w=(k+1)*roads[i][2]
            adj[a].append([b,w])
            adj[b].append([a,w])
        for i in range(1,n+1):         #建超级源点的边
            adj[0].append([i,appleCost[i-1]])
            adj[i].append([0,appleCost[i-1]])
        dist=[INF for _ in range(0,n+1)]
        dist[0]=0
        pqu=[]                          #定义小根堆pqu,元素为[length,vno]
        heapq.heappush(pqu,[0,0])      #源点元素进队
        while pqu:
            e=heapq.heappop(pqu)        #出队元素e
            u=e[1]                      #出队顶点u
            for edj in adj[u]:
                v,w=edj[0],edj[1]
                if dist[v]>dist[u]+w:    #边松驰
                    dist[v]=dist[u]+w
                    heapq.heappush(pqu,[dist[v],v])      #顶点v元素进队
        ans=[0]*n
        for i in range(1,n+1):
            ans[i-1]=dist[i]
        return ans
