class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        self.ans=[]             #存放所有的解
        x=[e for e in range(0,n)]
        self.dfs(x,n,0)                             #放置0～n-1的皇后
        return self.ans
    def dfs(self,x,n,i):     #回溯算法
        if i>=n:                            #所有皇后放置结束
            asolution=[]           #存放一个解
            for j in range(0,n):
                s=['.']*n              #存放一个皇后位置的字符串
                s[x[j]]='Q'
                asolution.append(''.join(s))
            self.ans.append(asolution)           #向ans中添加一个解
        else:
            for j in range(i,n):
                x[i],x[j]=x[j],x[i]                #交换x[i]与x[j]
                if self.valid(i,x):                  #剪支
                    self.dfs(x,n,i+1)
                x[i],x[j]=x[j],x[i]             #回溯：交换x[i]与x[j]
    def valid(self,i,x):      #测试(i,x[i])位置是否与前面的皇后不冲突
        if i==0:return True
        k=0
        while k<i:                                       #k=0～i-1是已放置了皇后的行
            if x[k]==x[i] or abs(x[k]-x[i])==abs(k-i): 
                return False                                   #(i,x[i])与皇后k有冲突
            k+=1
        return True
