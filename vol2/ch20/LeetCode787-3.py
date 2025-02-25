class Solution:
    def findCheapestPrice(self, n:int,flights:List[List[int]],src:int,dst:int,k:int)->int:
        INF=0x3f3f3f3f
        adj=[[] for _ in range(0,n)]                    #邻接表
        for i in range(0,len(flights)):      #遍历flights建立邻接表
            a,b,w=flights[i][0],flights[i][1],flights[i][2]   #<a,b>:w
            adj[a].append([b,w])
        dist=[INF for _ in range(n)]
        cnt=[INF for _ in range(n)]
        dist[src]=0
        cnt[src]=0
        pqu=[]          #定义优先队列pqu,元素为[length,vno,nums]
        heapq.heappush(pqu,[0,src,0])      #源点元素进队
        ans=INF
        while pqu:                      #队列不空循环
            e=heapq.heappop(pqu)        #出队元素e
            length,u,nums=e[0],e[1],e[2]          #出队顶点u
            if u==dst:ans=min(ans,length)       #找到目标
            for edj in adj[u]:
                v,w=edj[0],edj[1]           #相邻顶点为v
                nnums=nums+1
                if nnums>k+1:continue;   #剪支1
                if length+w<dist[v] or nnums<cnt[v]:  #剪支2
                    dist[v]=length+w
                    cnt[v]=nnums
                    if dist[v]>ans:continue         #剪支3
                    heapq.heappush(pqu,[dist[v],v,cnt[v]])
        if ans==INF:return -1
        else:return ans
