class Solution:
    def shortestDistance(self,maze:List[List[int]],start:List[int],dest:List[int])->int:
        INF=0x3f3f3f3f
        dr=[0,0,-1,1]            #水平方向偏移量
        dc=[-1,1,0,0]            #垂直方向偏移量
        m,n=len(maze),len(maze[0])
        qu=deque()      #定义队列，元素为[x,y]
        dist=[[INF]*n for i in range(0,m)]
        dist[start[0]][start[1]]=0
        qu.append([start[0],start[1]])
        while qu:
            [r,c]=qu.popleft()
            for di in range(0,4):  #从(r,c)扩展
                nr,nc=r,c
                delta=0
                while nr+dr[di]>=0 and nr+dr[di]<m and \
                    nc+dc[di]>=0 and nc+dc[di]<n and \
                    maze[nr+dr[di]][nc+dc[di]]==0:  #一直滚下去
                    nr,nc=nr+dr[di],nc+dc[di]       #按di方向滚到(nr,nc)
                    delta+=1
                if dist[r][c]+delta<dist[nr][nc]:   #边松弛
                    dist[nr][nc]=dist[r][c]+delta
                    qu.append([nr,nc])
        return -1 if dist[dest[0]][dest[1]]==INF else dist[dest[0]][dest[1]]
