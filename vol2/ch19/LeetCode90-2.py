class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        self.ans,x=[],[]            #x存放一个子集
        self.dfs(nums,x,0)
        return self.ans
    def dfs(self,a,x,j):				#回溯算法
        self.ans.append(x[:])
        for j1 in range(j,len(a)):
            if j1>j and a[j1-1]==a[j1]:continue
            x.append(a[j1])
            self.dfs(a,x,j1+1)
            x.pop()
