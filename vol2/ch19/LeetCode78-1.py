class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.ans,x=[],[]
        self.dfs(nums,x,0)
        return self.ans
    def dfs(self,a,x,i):  #回溯算法
        if i>=len(a):                            #到达一个叶子结点
            self.ans.append(copy.deepcopy(x))            #将子集x添加到ans中
        else:
            x.append(a[i])                      #选择a[i]
            self.dfs(a,x,i+1)
            x.pop()                       #回溯
            self.dfs(a,x,i+1)               #不选择a[i]
