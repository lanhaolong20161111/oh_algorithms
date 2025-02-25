class Solution:
    def findCheapestPrice(self,n:int,flights:List[List[int]],src:int,dst:int, k:int)->int:
        INF=0x3f3f3f3f
        adj=[[] for _ in range(0,n)]                    #邻接表
        for i in range(0,len(flights)):      #遍历flights建立邻接表
            a,b,w=flights[i][0],flights[i][1],flights[i][2]   #<a,b>:w
            adj[a].append([b,w])
        dist=[INF for _ in range(n)]
        cnt=[0 for _ in range(n)]
        dist[src]=0
        pqu=[]          								#定义pqu,结点类型为[length,vno,nums]
        heapq.heappush(pqu,[0,src,0])    #源点进队
        while pqu:                      #队列不空循环
            e=heapq.heappop(pqu)        #出队结点e
            length,u,nums=e[0],e[1],e[2]    #出队顶点u
            if u==dst:return length          #找到目标
            if nums>k:continue;            #剪支
            for edj in adj[u]:
                v,w=edj[0],edj[1]           #相邻顶点为v
                if length+w<dist[v]:    #剪支2：边长度松驰
                    dist[v]=length+w
                    cnt[v]=nums+1
                    heapq.heappush(pqu,[dist[v],v,cnt[v]])    #进队
                elif nums+1<cnt[v]:
                    heapq.heappush(pqu,[length+w,v,nums+1])    #进队
        return -1
