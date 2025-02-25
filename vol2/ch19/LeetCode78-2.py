class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.ans,x=[],[]
        self.dfs(nums,x,0)
        return self.ans
    def dfs(self,a,x,j):  #回溯算法
        self.ans.append(copy.deepcopy(x))   #将子集x添加到ans中
        for j1 in range(j,len(a)):      #j1≥j
            x.append(a[j1])
            self.dfs(a,x,j1+1)
            x.pop()
