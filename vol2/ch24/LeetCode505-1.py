class Solution:
    def shortestDistance(self,maze:List[List[int]],start:List[int],dest:List[int])->int:
        INF=0x3f3f3f3f
        self.dr=[0,0,-1,1]            #水平方向偏移量
        self.dc=[-1,1,0,0]            #垂直方向偏移量
        self.m,self.n=len(maze),len(maze[0])
        self.dist=[[INF]*self.n for i in range(0,self.m)]
        sr,sc=start[0],start[1]
        tr,tc=dest[0],dest[1]
        self.dist[sr][sc]=0
        self.dfs(maze,sr,sc)
        return -1 if self.dist[tr][tc]==INF else self.dist[tr][tc]
    def dfs(self,maze,r,c):						#回溯算法
        for di in range(0,4):
            delta,nr,nc=0,r,c
            while nr+self.dr[di]>=0 and nr+self.dr[di]<self.m \
                    and nc+self.dc[di]>=0 and nc+self.dc[di]<self.n \
                    and maze[nr+self.dr[di]][nc+self.dc[di]]==0:
                nr,nc=nr+self.dr[di],nc+self.dc[di]
                delta+=1
            if self.dist[r][c]+delta <self.dist[nr][nc]:   #边松驰
                self.dist[nr][nc]= self.dist[r][c]+delta 
                self.dfs(maze,nr,nc)
