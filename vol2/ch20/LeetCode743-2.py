class Solution:
    def networkDelayTime(self,times:List[List[int]],n:int,k:int) -> int:
        INF=0x3f3f3f3f
        adj=[[] for _ in range(0,n)]                    #邻接表
        for i in range(0,len(times)):      #遍历times建立邻接表
            a,b,w=times[i][0]-1,times[i][1]-1,times[i][2]   #<a,b>:w
            adj[a].append([b,w])
        s=k-1                      #源点为s
        dist=[INF for _ in range(n)]   #定义dist并初始化所有元素为INF
        dist[s]=0
        pqu=[]          #定义一个优先队列pqu,元素为[length,vno]
        heapq.heappush(pqu,[0,s])      #源点元素进队
        while pqu:                      #队列不空循环
            e=heapq.heappop(pqu)        #出队元素e
            u=e[1]                      #出队顶点u
            for edj in adj[u]:
                v,w=edj[0],edj[1]           #相邻顶点为v
                if dist[u]+w<dist[v]:    #边松驰:u到v有边且路径长度更短
                    dist[v]=dist[u]+w
                    heapq.heappush(pqu,[dist[v],v])      #顶点v进队
        ans=max(dist)
        if ans==INF:return -1
        else:return ans
