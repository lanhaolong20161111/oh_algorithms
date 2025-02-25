class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        self.dx=[0,0,1,-1]                   #水平方向偏移量
        self.dy=[1,-1,0,0]                   #垂直方向偏移量
        self.n=len(grid)                    #求n
        self.Init();
        for i in range(self.n):
            for j in range(self.n):
                if grid[i][j]==0:continue
                for di in range(0,4):
                    ni,nj=i+self.dx[di],j+self.dy[di]
                    if ni<0 or ni>=self.n or nj<0 or nj>=self.n:
                        continue
                    if grid[ni][nj]==0:continue
                    self.Union(self.pno(i,j),self.pno(ni,nj))
        a,b=-1,-1
        qu1,qu2=deque(),deque()
        dist1,dist2={},{}
        for i in range(self.n):
            for j in range(self.n):
                if grid[i][j]==0:continue   #跳过水域
                cno=self.pno(i,j)
                root=self.Find(cno)
                if a==-1:
                    a=root                  #第一次归入A岛
                elif a!=root and b==-1:
                    b=root                  #第一次归入B岛
                if a==root:                 #归入A岛
                    qu1.append([i,j])
                    dist1[cno]=0
                elif b==root:               #归入A岛
                    qu2.append([i,j])
                    dist2[cno]=0
        while qu1 and qu2:                  #双向多起点BFS
            ans=-1
            if len(qu1)<len(qu2):
                ans=self.extend(qu1,dist1,dist2)
            else:
                ans=self.extend(qu2,dist2,dist1)
            if ans!=-1:return ans-1
        return -1

    def pno(self,i,j):                  #二维转换为一维
        return i*self.n+j

    def Init(self):                     #并查集初始化
        self.parent=[0]*(self.n*self.n+5)
        self.rnk=[0]*(self.n*self.n+5)
        for i in range(0,self.n):
            for j in range(0,self.n):
                k=self.pno(i,j)
                self.parent[k]=k
                self.rnk[k]=0

    def Find(self,x):                  #并查集中查找x结点的根结点
        if x!=self.parent[x]:
            self.parent[x]=self.Find(self.parent[x])  #路径压缩
        return self.parent[x]

    def Union(self,x,y):                #合并
        rx=self.Find(x)
        ry=self.Find(y)
        if rx==ry:return;               #x和y属于同一棵树的情况
        if self.rnk[rx]<self.rnk[ry]:
            self.parent[rx]=ry          #rx结点作为ry的孩子
        else:
            if self.rnk[rx]==self.rnk[ry]:
                self.rnk[rx]+=1         #秩相同，合并后rx的秩增1
            self.parent[ry]=rx          #ry结点作为rx的孩子

    def extend(self,qu,dist1,dist2):
        cnt=len(qu)
        for _ in range(0,cnt):
            [x,y]=qu.popleft()
            cdist=dist1[self.pno(x,y)]
            for di in range(0,4):
                nx,ny=x+self.dx[di],y+self.dy[di]
                no=self.pno(nx,ny)
                if nx<0 or nx>=self.n or ny<0 or ny>=self.n:
                    continue
                if no in dist1:continue
                if no in dist2:return cdist+1+ dist2[no]
                qu.append([nx,ny])
                dist1[no]=cdist+1
        return -1
