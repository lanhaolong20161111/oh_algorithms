class Solution:
    def allPathsSourceTarget(self, graph:List[List[int]])->List[List[int]]:
        self.ans,x=[],[0]
        self.dfs(graph,x)
        return self.ans
    def dfs(self,graph,x):				#回溯算法
        if x[-1]==len(graph)-1:
            self.ans.append(copy.deepcopy(x))
        else:
            for j in graph[x[-1]]:
                x.append(j)
                self.dfs(graph,x)
                x.pop()
