class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        self.ans,self.x=[],[]
        self.dfs(n,0,0)
        return self.ans
    def dfs(self,n,left,right):   #回溯算法
        if len(self.x)==2*n:
            self.ans.append(''.join(self.x))
        else:
            if left<n:
                self.x.append('(');       #选择'('
                self.dfs(n,left+1,right)
                self.x.pop()           #回溯
            if right<left:
                self.x.append(')')       #选择')'
                self.dfs(n,left,right+1)
                self.x.pop()           #回溯
