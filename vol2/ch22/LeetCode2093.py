class Solution:
    def minimumCost(self,n:int,highways:List[List[int]],discounts:int)->int:
        INF=0x3f3f3f3f
        adj=[[] for _ in range(n)]    #邻接表
        for a,b,w in highways:
            adj[a].append([b,w])
            adj[b].append([a,w])
        pqu=[]                      #定义小根堆pqu,元素为[花费,vno,打折次数]
        heapq.heappush(pqu,[0,0,0])      #源点元素进队
        dist=[[INF]*(discounts+1) for _ in range(n)]
        while pqu:
            e=heapq.heappop(pqu)            #出队元素e
            cost,u,disc=e[0],e[1],e[2]
            if disc>discounts:continue      #剪支
            if u==n-1:return cost
            if cost<dist[u][disc]:
                dist[u][disc]=cost
                for v,w in adj[u]:
                    heappush(pqu,(cost+w,v,disc))
                    heappush(pqu,(cost+w//2,v,disc+1))
        return -1
