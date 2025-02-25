class Solution:
  def shortestPathLength(self, graph: List[List[int]]) -> int:
    n=len(graph)                   #顶点个数
    endstate=(1<<n)-1              #目标状态
    visited=[[0 for _ in range(1<<n)] for _ in range(n)]
    qu=deque()
    for i in range(n):      #所有顶点及其初始状态进队
      state=self.addj(0,i)
      qu.append([i,state])
      visited[i][state]=1
    bestd=0
    while qu:
      cnt=len(qu)              #求队中元素个数
      for i in range(0,cnt):      #处理该层的所有元素
          [u,state]=qu.popleft()       #出队(u,state)
          if state==endstate:            #第一次找到目标状态则返回
            return bestd
          for v in graph[u]:           #找u的所有相邻顶点v
            state1=self.addj(state,v) #添加顶点v
            if visited[v][state1]==1:  #已经访问则跳过
              continue;
            qu.append([v,state1])
            visited[v][state1]=1
      bestd+=1                          #搜索一层，路径长度增加1
    return -1                            #没有找到目标状态返回-1
  def addj(self,state,j):             #在state添加顶点j
    return state | (1<<j)
