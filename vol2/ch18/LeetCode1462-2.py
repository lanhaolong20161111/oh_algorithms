class Solution:
    def checkIfPrerequisite(self,n:int,prereqs,ques) -> List[bool]:
        self.adj=[[] for _ in range(0,n)]          #邻接表
        self.path=[[False for _ in range(n)] for _ in range(n)];
        for i in range(0,len(prereqs)):    #由列表创建邻接表
            a=prereqs[i][0]                #[a,b]表示a是b的先修课程
            b=prereqs[i][1]
            self.adj[a].append(b)                #用<a,b>表示即先修a,再修b
        for i in range(0,n):
            self.bfs(n,i)
        ans=[False for _ in range(0,len(ques))]     #存放答案
        for i in range(0,len(ques)):
            ans[i]=self.path[ques[i][0]][ques[i][1]]
        return ans
    def bfs(self,n,i):                              #从课程i出发广度优先搜索
        qu=deque()                              #定义一个队列qu
        self.path[i][i]=True                            #自己到自己有路径
        qu.append(i)                                 #课程i进队
        while qu:                      #队不空循环
            cnt=len(qu)
            for j in range(0,cnt):
                u=qu.popleft()         #出队课程u
                for v in self.adj[u]:                 #考虑课程u的出边课程v
                    if self.path[i][v]:continue;
                    self.path[i][v]=True                #表示课程i到v有路径
                    qu.append(v)                     #课程v进队
