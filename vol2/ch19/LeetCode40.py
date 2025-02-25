class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        self.ans,x=[],[]
        candidates.sort()                    #排序以便去重
        self.dfs(candidates,target,x,0,0);                               #cs和j从0开始
        return self.ans
    def dfs(self,a,t,x,cs,j):         #回溯算法
        if cs==t:
            self.ans.append(copy.deepcopy(x))
        else:
            for j1 in range(j,len(a)):
                if a[j1]+cs>t:continue                       #剪支
                if j1>j and a[j1]==a[j1-1]:continue            #跳过重复的元素
                cs+=a[j1]
                x.append(a[j1])
                self.dfs(a,t,x,cs,j1+1)            #每个元素只能用一次，所以j1+1
                cs-=a[j1]
                x.pop()                                  #回溯
