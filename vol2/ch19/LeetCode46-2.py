class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        self.ans,x=[],nums
        self.dfs(x,0)
        return self.ans
    def dfs(self,x,i):  #回溯算法
        n=len(x)
        if i>=n:
            self.ans.append(list(x))    #等同于x深拷贝
        else:
            for j in range(i,n):
                x[i],x[j]=x[j],x[i]     #交换x[i]与x[j]
                self.dfs(x,i+1)
                x[i],x[j]=x[j],x[i]     #回溯：交换x[i]与x[j]
