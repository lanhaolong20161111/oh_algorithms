class Solution:
    def findShortestWay(self, maze: List[List[int]], ball: List[int], hole: List[int])->str:
        INF=0x3f3f3f3f
        self.dr=[1,0,0,-1]                      #垂直方向偏移量
        self.dc=[0,-1,1,0]                      #水平方向偏移量
        self.dirstr=["d","l","r","u"]           #方位：字典序最小
        self.m,self.n=len(maze),len(maze[0])
        self.dist=[[INF for _ in range(self.n)] for _ in range(self.m)]
        self.path=[["" for _ in range(self.n)] for _ in range(self.m)]
        sr,sc=ball[0],ball[1]
        self.hr,self.hc=hole[0],hole[1]
        self.dist[sr][sc]=0
        self.dfs(maze,sr,sc)
        ans=self.path[self.hr][self.hc]
        return "impossible" if ans=="" else ans
    def dfs(self,maze,r,c):
        for di in range(0,4):
            delta=0
            nr,nc=r,c
            while nr+self.dr[di]>=0 and nr+self.dr[di]<self.m  \
                    and nc+self.dc[di]>=0 and nc+self.dc[di]<self.n and \
                    maze[nr+self.dr[di]][nc+self.dc[di]]==0: 
                nr+=self.dr[di]
                nc+=self.dc[di]
                delta+=1
                if nr==self.hr and nc==self.hc:   #(nr,nc)为洞
                    break;
            curdist=self.dist[r][c]+delta
            curpath=self.path[r][c]+self.dirstr[di]
            if curdist<self.dist[nr][nc]:           #边松驰
                self.dist[nr][nc]=curdist
                self.path[nr][nc]=curpath
                if nr!=self.hr or nc!=self.hc:       #(nr,nc)不是洞
                    self.dfs(maze,nr,nc)
            elif curdist==self.dist[nr][nc]:
                if curpath<self.path[nr][nc]:     #找最小序路径
                    self.path[nr][nc]=curpath;
                    if nr!=self.hr or nc!=self.hc:    #(nr,nc)不是洞
                        self.dfs(maze,nr,nc)
