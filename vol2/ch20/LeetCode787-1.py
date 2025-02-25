class Solution:
    def findCheapestPrice(self, n:int,flights:List[List[int]],src:int,dst:int,k:int)->int:
        INF=0x3f3f3f3f
        adj=[[] for _ in range(0,n)]                    #邻接表
        for i in range(0,len(flights)):      #遍历flights建立邻接表
            a,b,w=flights[i][0],flights[i][1],flights[i][2]   #<a,b>:w
            adj[a].append([b,w])
        dist=[INF for _ in range(n)] 
        dist[src]=0
        qu=deque()          #定义队列qu,元素为[vno,length,nums]
        qu.append([src,0,0])    #源点元素进队
        ans=INF
        while qu:                      #队列不空循环
            e=qu.popleft()        #出队元素e
            u,length,nums=e[0],e[1],e[2]          #出队顶点u
            if u==dst:ans=min(ans,length)       #找到目标
            for edj in adj[u]:
                v,w=edj[0],edj[1]           #相邻顶点为v
                if nums>k:continue;   #剪支1
                if length+w<dist[v]:    #剪支2：边长度松驰
                    dist[v]=length+w
                    if dist[v]<ans:     #剪支3
                        qu.append([v,dist[v],nums+1])
        if ans==INF:return -1
        else:return ans
