class Solution:
    def judgePoint24(self, cards: List[int]) -> bool:
        self.ans,a=False,[]
        for e in cards:a.append(e)
        self.dfs(a)
        return self.ans
    def dfs(self,a):      #回溯算法
        n=len(a)
        if n==1 and abs(a[0]-24)<0.0001:
            self.ans=True
        elif n>1 and not self.ans:
            for i in range(0,n):        #由a生成b
                for j in range(0,n):
                    if i==j:continue;
                    b=[]
                    for k in range(0,n):
                        if k!=i and k!=j:b.append(a[k])
                    b.append(a[i]+a[j])         #选择+
                    self.dfs(b)
                    b.pop()                     #回溯
                    b.append(a[i]-a[j])         #选择-
                    self.dfs(b)
                    b.pop()                     #回溯
                    b.append(a[i]*a[j])         #选择*
                    self.dfs(b)
                    b.pop()                     #回溯
                    if a[j]!=0.0:
                        b.append(a[i]/a[j])     #选择/
                        self.dfs(b)
                        b.pop()                     #回溯
