class QNode:                    #优先队列结点类型
    r,c=0,0
    f,g,h=0,0,0
    def __lt__(self,other):   #用于按f越小越优先出队
        if self.f<other.f:return True
        else:return False
class Solution:
    def findShortestWay(self, maze:List[List[int]],ball:List[int],hole:List[int])->str:
        INF=0x3f3f3f3f
        dr=[1,0,0,-1]               #水平方向偏移量
        dc=[0,-1,1,0]               #垂直方向偏移量
        dirstr=["d","l","r","u"]    #方位：字典序最小
        m,n=len(maze),len(maze[0])
        pqu=[]                      #定义小根堆，元素为QNode类型
        e=QNode()
        e.r,e.c=ball[0],ball[1]
        e.g,e.h=0,self.geth(ball[0],ball[1],hole[0],hole[1])
        e.f=e.g+e.h
        heapq.heappush(pqu,e)
        minf=[[INF for _ in range(n)] for _ in range(0,m)]
        path=[["" for _ in range(n)] for _ in range(0,m)]
        minf[ball[0]][ball[1]]=0
        while pqu:
            e=heapq.heappop(pqu)
            r,c=e.r,e.c
            for di in range(0,4):  #从(r,c)扩展
                nr,nc=r,c
                delta=0
                while nr+dr[di]>=0 and nr+dr[di]<m and \
                    nc+dc[di]>=0 and nc+dc[di]<n and \
                    maze[nr+dr[di]][nc+dc[di]]==0:  #一直滚下去
                    nr,nc=nr+dr[di],nc+dc[di]       #按di方向滚到(nr,nc)
                    delta+=1									#走的空地数
                    if nr==hole[0] and nc==hole[1]: 
                        break                     #找到洞时将其作为停靠点
                e1=QNode()
                e1.r,e1.c=nr,nc
                e1.g=e.g+delta
                e1.h=self.geth(nr,nc,hole[0],hole[1])
                e1.f=e1.g+e1.h
                curpath=path[r][c]+dirstr[di]
                if e1.f<minf[nr][nc]:           #当前路径的f更短
                    minf[nr][nc]=e1.f
                    path[nr][nc]=curpath
                    heapq.heappush(pqu,e1)
                elif e1.f==minf[nr][nc]:            #f相同时
                    if curpath<path[nr][nc]:      #取字段序比小的路径
                        path[nr][nc]=curpath
                        heapq.heappush(pqu,e1)
        if path[hole[0]][hole[1]]=="":return "impossible"
        else:return path[hole[0]][hole[1]]
    def geth(self,x,y,gx,gy):       #计算启发式函数值
        return abs(gx-x)+abs(gy-y)
