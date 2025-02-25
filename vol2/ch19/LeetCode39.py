class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.ans=[]
        self.x=[]
        self.dfs(candidates,target,0)                           #i从0开始
        return self.ans
    def dfs(self,a,rt,i):   #回溯算法
        if rt==0:       #找到一个解
            self.ans.append(copy.deepcopy(self.x))
        elif i<len(a):              #a尚未遍历完毕
            self.dfs(a,rt,i+1)          #不选择a[i]
            if a[i]<=rt:                #不超重时选择a[i]
                self.x.append(a[i])
                self.dfs(a,rt-a[i],i)
                self.x.pop()
