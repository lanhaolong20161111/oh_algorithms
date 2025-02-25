class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        self.dfs(board,0,0)
    def dfs(self,board,i,j):						#回溯算法
        if j==9:
            i=i+1          #一行完后进入下一行
            j=0
        if i==9:return True     #到达一个叶子结点
        if board[i][j]!='.':            #跳过非空单元
            return self.dfs(board,i,j+1)
        for k in range(1,10):        #空单元尝试'1'-'9'
            ch=str(k)
            if self.isValid(board,i,j,ch):
                board[i][j]=ch
                if self.dfs(board,i,j+1):
                    return True #若找到一个解返回True
                board[i][j]='.'            #回溯
        return False
    def isValid(self,board,i,j,val):
        starti=(i//3)*3         #求(i,j)所在九宫格的左上角位置
        startj=(j//3)*3
        for k in range(0,9):
            if board[i][k]==val:      #同一行重复返回false
                return False
            if board[k][j]==val:      #同一列重复返回false
                return False
            if board[starti+k//3][startj+k%3]==val:
                return False           #当前九格宫中重复返回false
        return True
