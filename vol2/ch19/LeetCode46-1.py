class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n=len(nums)
        self.ans,self.used=[],[0]*n
        x=[]
        self.dfs(nums,x,0)
        return self.ans
    def dfs(self,a,x,i):    #回溯算法
        n=len(a)
        if i>=n:
            self.ans.append(list(x))				#等同于x深拷贝
        else:
            for j in range(0,n):
                if self.used[j]:continue                #剪支：跳过已经使用过的a[j]
                x.append(a[j])
                self.used[j]=1                          #选择a[j]
                self.dfs(a,x,i+1)                       #转向解空间树的下一层
                self.used[j]=0                          #回溯
                x.pop()
