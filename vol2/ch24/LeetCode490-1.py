class Solution:
    def hasPath(self,maze:List[List[int]],start:List[int],dest:List[int])->bool:
        self.dr=[0,0,-1,1]            #水平方向偏移量
        self.dc=[-1,1,0,0]            #垂直方向偏移量
        self.m,self.n=len(maze),len(maze[0])
        self.visited=[[False]*self.n for i in range(0,self.m)]  #访问标记数组
        sr,sc=start[0],start[1]
        self.tr,self.tc=dest[0],dest[1]
        self.visited[sr][sc]=True
        return self.dfs(maze,sr,sc)
    def dfs(self,maze,r,c):
        if r==self.tr and c==self.tc:
            return True
        else:
            for di in range(0,4):   #从(r,c)扩展
                nr,nc=r,c
                while nr+self.dr[di]>=0 and nr+self.dr[di]<self.m and \
                    nc+self.dc[di]>=0 and nc+self.dc[di]<self.n and \
                    maze[nr+self.dr[di]][nc+self.dc[di]]==0:   #一直滚下去
                    nr,nc=nr+self.dr[di],nc+self.dc[di] #按di方向滚到(nr,nc)
                if self.visited[nr][nc]:continue
                self.visited[nr][nc]=True
                if self.dfs(maze,nr,nc):return True
            return False
