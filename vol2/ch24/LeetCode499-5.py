class Solution:
    def findShortestWay(self, maze:List[List[int]],ball:List[int],hole:List[int])->str:
        INF=0x3f3f3f3f
        dr=[1,0,0,-1]            #水平方向偏移量
        dc=[0,-1,1,0]            #垂直方向偏移量
        dirstr=["d","l","r","u"]    #方位：字典序最小
        m,n=len(maze),len(maze[0])
        dist=[[INF for _ in range(n)] for _ in range(m)]
        path=[["" for _ in range(n)] for _ in range(m)]
        S=[[False for _ in range(n)] for _ in range(m)]
        pqu=[]                      #定义小根堆，元素为[steps,r,c]
        heapq.heappush(pqu,[0,ball[0],ball[1]])
        dist[ball[0]][ball[1]]=0
        S[ball[0]][ball[1]]=True
        while pqu:
            [steps,r,c]=heapq.heappop(pqu)
            S[r][c]=True                    #将(r,c)添加到S集合中
            if r==hole[0] and c==hole[1]:   #一旦找到目的地则返回
                return path[r][c]
            for di in range(0,4):  #从(r,c)扩展
                nr,nc=r,c
                delta=0
                while nr+dr[di]>=0 and nr+dr[di]<m and \
                    nc+dc[di]>=0 and nc+dc[di]<n and \
                    maze[nr+dr[di]][nc+dc[di]]==0:  #一直滚下去
                    nr,nc=nr+dr[di],nc+dc[di]       #按di方向滚到(nr,nc)
                    delta+=1                                    #走的空地数
                    if nr==hole[0] and nc==hole[1]: 
                        break                     #找到洞时将其作为停靠点
                if S[nr][nc]:continue           #仅修改不在S中的位置
                curdist=dist[r][c]+delta
                curpath=path[r][c]+dirstr[di]
                if curdist<dist[nr][nc]:            #比较求最短路径
                    dist[nr][nc]=curdist
                    path[nr][nc]=curpath
                    heapq.heappush(pqu,[dist[nr][nc],nr,nc])
                elif curdist==dist[nr][nc]:      #相同长度时
                    if curpath<path[nr][nc]:
                        path[nr][nc]=curpath
                        heapq.heappush(pqu,[dist[nr][nc],nr,nc])
        return "impossible"
