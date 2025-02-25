class Solution:
    def checkIfPrerequisite(self,n:int,prereqs,ques) -> List[bool]:
        self.adj=[[] for _ in range(0,n)]          #邻接表
        self.path=[[False for _ in range(n)] for _ in range(n)];
        for i in range(0,len(prereqs)):    #由列表创建邻接表
            a=prereqs[i][0]                #[a,b]表示a是b的先修课程
            b=prereqs[i][1]
            self.adj[a].append(b)                #用<a,b>表示即先修a,再修b
        for i in range(0,n):       #求课程i到哪些课程有路径
            self.dfs(n,i,i);
        ans=[False for _ in range(0,len(ques))]     #存放答案
        for i in range(0,len(ques)):
            ans[i]=self.path[ques[i][0]][ques[i][1]]
        return ans
    def dfs(self,n,i,u):       #从课程u出发的深度优先遍历
        self.path[i][u]=True                #表示课程i到u有路径
        for v in self.adj[u]:             #考虑课程u的出边课程v
            if self.path[i][v]:continue
            self.path[i][v]=True            #表示课程i到v有路径
            self.dfs(n,i,v)                 #从课程v出发搜索
