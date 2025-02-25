class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        self.dr=[0,0,1,-1]                    #按行方向的偏移量
        self.dc=[1,-1,0,0]                       #按列方向的偏移量
        self.m,self.n=len(board),len(board[0])
        self.visited=[[0]*self.n for i in range(0,self.m)]  #访问标记数组
        for r in range(0,self.m):
            for c in range(0,self.n):
                if board[r][c]==word[0]:
                    self.visited[r][c]=1
                    self.ans=False
                    self.dfs(board,word,r,c,1)
                    if self.ans:return True
                    self.visited[r][c]=0
        return False
    def dfs(self,board,word,r,c,i):				#回溯算法
        if i>=len(word):
            self.ans=True
        elif self.ans==False:
            for di in range(0,4):				#四周试探
                nr=r+self.dr[di]    #求di方位的相邻位置[nr,nc]
                nc=c+self.dc[di]
                if nr<0 or nr>=self.m or nc<0 or nc>=self.n:
                    continue       #跳过无效的[nr,nc]
                if self.visited[nr][nc]==1:
                    continue       #跳过已经访问的[nr,nc]
                if board[nr][nc]==word[i]:
                    self.visited[nr][nc]=1
                    self.dfs(board,word,nr,nc,i+1)
                    self.visited[nr][nc]=0
