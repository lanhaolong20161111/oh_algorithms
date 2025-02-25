class Solution:
  def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
    n=len(graph)
    ans=[]
    self.safe=[False]*n   #初始化safe
    for i in range(0,n):  #试探每个顶点i
      self.visited=[False]*n  #初始化visited
      if self.dfs(graph,i):
        ans.append(i)
    return ans
  def dfs(self,graph,i):    #从i出发DFS是否找到终点
    if self.safe[i]:return True         #i是安全的，返回True
    if self.visited[i]:return False   #i访问过，返回False
    if len(graph[i])==0:    #到达终点i（没有出边）
      self.safe[i]=True             #i是安全的
      return True;              #返回True
    self.visited[i]=True
    for j in graph[i]:      #遍历i的每个相邻点j
      if not self.dfs(graph,j): #任意一边不满足返回假
        return False
    self.safe[i]=True               #i是安全的
    return True               #返回true
