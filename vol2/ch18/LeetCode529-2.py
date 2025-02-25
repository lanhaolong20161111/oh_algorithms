class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        self.dx=[0,1,0,-1,1,1,-1,-1]  #水平方向偏移量
        self.dy=[1,0,-1,0,1,-1,1,-1]  #垂直方向偏移量
        x,y=click[0],click[1]
        self.m,self.n=len(board),len(board[0])
        if board[x][y]=='M':       #规则1
            board[x][y]='X'
            return board
        cnt=self.Count(board,x,y)
        if cnt==0:                #cnt=0:规则2
            board[x][y]='B'
            self.bfs(board,x,y)
        else:                       #cnt>0:规则3
            board[x][y]=str(cnt)    #转换为数字字符
        return board
    def Count(self,board,x,y):
        cnt=0
        for di in range(0,8):      #求相邻地雷个数cnt
            nx,ny=x+self.dx[di],y+self.dy[di]
            if nx<0 or nx>=self.m or ny<0 or ny>=self.n:
                continue					#忽略超界的位置
            if board[nx][ny]=='M':cnt+=1
        return cnt
    def bfs(self,board,x,y):
        qu=deque()								#定义一个队列
        qu.append([x,y])
        while len(qu)>0:
            [x,y]=qu.popleft();                 #出队元素[x,y]
            for di in range(0,8):
                nx,ny=x+self.dx[di],y+self.dy[di]
                if nx<0 or nx>=self.m or ny<0 or ny>=self.n:
                    continue            #忽略超界的位置
                if board[nx][ny]=='B':      #为'B'时跳过
                    continue;
                cnt=self.Count(board,nx,ny)    #求(nx,ny)周围的地雷数
                if cnt==0:                      #cnt=0:规则2
                    board[nx][ny]='B'
                    qu.append([nx,ny])
                else:                       #cnt>0:规则3
                    board[nx][ny]=str(cnt)    #转换为数字字符
