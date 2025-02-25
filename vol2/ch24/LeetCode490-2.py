class Solution:
    def hasPath(self,maze:List[List[int]],start:List[int],dest:List[int])->bool:
        dr=[0,0,-1,1]            #水平方向偏移量
        dc=[-1,1,0,0]            #垂直方向偏移量
        m,n=len(maze),len(maze[0])
        visited=[[False]*n for i in range(0,m)]  #访问标记数组
        qu=deque()              #定义队列，元素为[r,c]
        qu.append([start[0],start[1]])
        visited[start[0]][start[1]]=True
        while qu:
            [r,c]=qu.popleft()
            if r==dest[0] and c==dest[1]:
                return True
            for di in range(0,4):   #从(r,c)扩展
                nr,nc=r,c
                while nr+dr[di]>=0 and nr+dr[di]<m and \
                    nc+dc[di]>=0 and nc+dc[di]<n and \
                    maze[nr+dr[di]][nc+dc[di]]==0:  #一直滚下去
                    nr,nc=nr+dr[di],nc+dc[di] #按di方向滚到(nr,nc)
                if visited[nr][nc]:continue
                visited[nr][nc]=True
                qu.append([nr,nc])
        return False
