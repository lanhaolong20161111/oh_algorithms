class Solution:
    def shortestDistance(self,maze:List[List[int]],start:List[int],dest:List[int])->int:
        INF=0x3f3f3f3f
        dr=[0,0,-1,1]            #水平方向偏移量
        dc=[-1,1,0,0]            #垂直方向偏移量
        m,n=len(maze),len(maze[0])
        pqu=[]      #定义小根堆，元素为[steps,r,c]
        dist=[[INF]*n for i in range(0,m)]
        dist[start[0]][start[1]]=0
        heapq.heappush(pqu,[0,start[0],start[1]])
        while pqu:
            [steps,r,c]=heapq.heappop(pqu)
            for di in range(0,4):  #从(r,c)扩展
                nr,nc=r,c
                delta=0
                while nr+dr[di]>=0 and nr+dr[di]<m and \
                    nc+dc[di]>=0 and nc+dc[di]<n and \
                    maze[nr+dr[di]][nc+dc[di]]==0:  #一直滚下去
                    nr,nc=nr+dr[di],nc+dc[di]       #按di方向滚到(nr,nc)
                    delta+=1									#走的空地数
                if dist[r][c]+delta<dist[nr][nc]:   #边松弛
                    dist[nr][nc]=dist[r][c]+delta
                    heapq.heappush(pqu,[dist[nr][nc],nr,nc])
        return -1 if dist[dest[0]][dest[1]]==INF else dist[dest[0]][dest[1]]
