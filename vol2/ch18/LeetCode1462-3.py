class Solution:
    def checkIfPrerequisite(self,n:int,prereqs,ques) -> List[bool]:
        self.adj=[[] for _ in range(0,n)]          #邻接表
        self.path=[[False for _ in range(n)] for _ in range(n)];
        self.degree=[0 for _ in range(0,n)]
        for i in range(0,len(prereqs)):    #由列表创建邻接表
            a=prereqs[i][0]                #[a,b]表示a是b的先修课程
            b=prereqs[i][1]
            self.adj[a].append(b)                #用<a,b>表示即先修a,再修b
            self.degree[b]+=1
        self.topsort(n)
        ans=[False for _ in range(0,len(ques))]     #存放答案
        for i in range(0,len(ques)):
            ans[i]=self.path[ques[i][0]][ques[i][1]]
        return ans
    def topsort(self,n):                #拓扑排序
        st=deque()                      #用双端队列作为栈
        for i in range(0,n):   #入度为0的课程进栈
            if self.degree[i]==0:st.append(i)
        while st:           #栈不空循环
            i=st.pop()    #出栈课程i
            for j in self.adj[i]:        #考虑课程i的出边课程j
                self.degree[j]-=1             #课程k的入度减1
                self.path[i][j]=True         #i是j的先修课程
                for k in range(0,n):   #i的先修课程k也是j的先修课程
                    if self.path[k][i]:self.path[k][j]=True
                if self.degree[j]==0:st.append(j)
