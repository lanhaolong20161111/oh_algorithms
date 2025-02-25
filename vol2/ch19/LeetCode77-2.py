class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        self.ans,x=[],[]
        self.dfs(n,k,x,1)
        return self.ans
    def dfs(self,n,k,x,i):							#回溯算法
        if len(x)==k:
            self.ans.append(copy.deepcopy(x))
        else:
            for j in range(i,n+1):
                x.append(j)
                self.dfs(n,k,x,j+1)
                x.pop()
