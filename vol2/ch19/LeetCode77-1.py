class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        self.ans,x=[],[]
        self.dfs(n,k,0,x,1)
        return self.ans
    def dfs(self,n,k,cnt,x,i):					#回溯算法
        if i>n:
            if cnt==k:
                self.ans.append(copy.deepcopy(x))
        else:
            x.append(i)             #选择i
            self.dfs(n,k,cnt+1,x,i+1)
            x.pop()
            self.dfs(n,k,cnt,x,i+1)       #不选择i
