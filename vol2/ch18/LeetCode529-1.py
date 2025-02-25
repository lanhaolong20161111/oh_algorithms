class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        self.dx=[0,1,0,-1,1,1,-1,-1]  #水平方向偏移量
        self.dy=[1,0,-1,0,1,-1,1,-1]  #垂直方向偏移量
        x,y=click[0],click[1]
        self.m,self.n=len(board),len(board[0])
        if board[x][y]=='M':       #规则1
            board[x][y]='X'
        else:
            self.dfs(board,x,y)
        return board
    def Count(self,board,x,y):
        cnt=0
        for di in range(0,8):      #求相邻地雷个数cnt
            nx,ny=x+self.dx[di],y+self.dy[di]
            if nx<0 or nx>=self.m or ny<0 or ny>=self.n:  #忽略超界的位置
                continue
            if board[nx][ny]=='M':cnt+=1
        return cnt
    def dfs(self,board,x,y):
        cnt=self.Count(board,x,y)
        if cnt==0:       #cnt=0:规则 2
            board[x][y]='B'
            for di in range(0,8):
                nx,ny=x+self.dx[di],y+self.dy[di]
                if nx<0 or nx>=self.m or ny<0 or ny>=self.n:  
                    continue            #忽略超界的位置
                if board[nx][ny]=='B': 
                    continue            #跳过为'B'的位置
                self.dfs(board,nx,ny)
        else:                        #cnt>0:规则3
            board[x][y]=str(cnt)    #转换为数字字符
