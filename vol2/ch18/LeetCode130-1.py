class Solution:
    def solve(self, board: List[List[str]]) -> None:
        self.dx=[0,0,1,-1]                        #水平方向偏移量
        self.dy=[1,-1,0,0]                       #垂直方向偏移量
        self.m,self.n=len(board),len(board[0])
        for i in range(0,self.m):    #从最外面一圈找到一个'O'
            for  j in range(0,self.n):
                if (i==0 or i==self.m-1 or j==0 or j==self.n-1) and board[i][j]=='O':
                    self.dfs(board,i,j)
        for i in range(0,self.m):                #替换
            for j in range(0,self.n):
                if board[i][j]=='$':
                    board[i][j]='O'
                elif board[i][j]=='O':
                    board[i][j]='X'
    def dfs(self,board,i,j):            #(i,j)位置出发深度优先遍历
        board[i][j]='$'
        for di in range(0,4):
            x,y=i+self.dx[di],j+self.dy[di]
            if x<0 or x>=self.m or y<0 or y>=self.n or board[x][y]!='O': 
                continue                            #超界或者不是'O'时跳过
            self.dfs(board,x,y)
