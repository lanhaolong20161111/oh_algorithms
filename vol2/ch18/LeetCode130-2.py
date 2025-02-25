class Solution:
    def solve(self, board: List[List[str]]) -> None:
        self.dx=[0,0,1,-1]                      #水平方向偏移量
        self.dy=[1,-1,0,0]                      #垂直方向偏移量
        self.m,self.n=len(board),len(board[0])
        self.qu=deque()                         #定义一个全局队列
        for i in range(0,self.m):    #从最外面一圈找到一个'O'
            for  j in range(0,self.n):
                if (i==0 or i==self.m-1 or j==0 or j==self.n-1) and board[i][j]=='O':
                    board[i][j]='$'        #用特殊字符'$'替换
                    self.qu.append([i,j]);   #将最外面一圈的所有'O'进队
        self.bfs(board)
        for i in range(0,self.m):                #替换
            for j in range(0,self.n):
                if board[i][j]=='$':
                    board[i][j]='O'
                elif board[i][j]=='O':
                    board[i][j]='X'

    def bfs(self,board):            						#(i,j)位置出发广度优先遍历
        while len(self.qu)>0:        					#队不空时循环
            [i,j]=self.qu.popleft();                 #出队元素[i,j]
            for di in range(0,4):
                x,y=i+self.dx[di],j+self.dy[di]   #求出di方位的相邻位置(x,y)
                if x<0 or x>=self.m or y<0 or y>=self.n: 
                    continue                    #超界时跳过
                if board[x][y]!='O':
                    continue
                board[x][y]='$';                 #访问(x,y)
                self.qu.append([x,y])     #(x,y)进队
