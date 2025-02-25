class Solution:
    def findCheapestPrice(self, n:int,flights:List[List[int]],src:int,dst:int,k:int)->int:
        INF=0x3f3f3f3f
        adj=[[] for _ in range(0,n)]                    #邻接表
        for i in range(0,len(flights)):      #遍历flights建立邻接表
            a,b,w=flights[i][0],flights[i][1],flights[i][2]   #<a,b>:w
            adj[a].append([b,w])
        dist=[INF for _ in range(n)]   #定义dist并初始化所有元素为INF
        dist[src]=0
        qu=deque()          #定义一个队列qu,元素为[vno,length]
        qu.append([src,0])    #源点元素进队
        k+=1
        while k>0 and qu:                      #队列不空循环
            cnt=len(qu)
            for _ in range(0,cnt):
                e=qu.popleft()        #出队元素e
                u,length=e[0],e[1]          #出队顶点u
                for edj in adj[u]:
                    v,w=edj[0],edj[1]           #相邻顶点为v
                    if length+w<dist[v]: 	#剪支2：边长度松驰
                        dist[v]=length+w
                        qu.append([v,dist[v]])
            k-=1
        if dist[dst]==INF:return -1
        else:return dist[dst]
