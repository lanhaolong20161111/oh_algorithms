class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        self.ans,x=[],[]
        self.dfs(nums,x,0)
        return self.ans
    def dfs(self,a,x,j):				#回溯算法
        if len(x)>1:
            self.ans.append(copy.deepcopy(x))
        used=set()                              #使用集合实现本层元素除重
        for j1 in range(j,len(a)):   
            if len(x)>0 and a[j1]<x[-1]:continue
            if a[j1] in used:continue
            x.append(a[j1])    
            used.add(a[j1])      
            self.dfs(a,x,j1+1)
            x.pop()                             #回溯
