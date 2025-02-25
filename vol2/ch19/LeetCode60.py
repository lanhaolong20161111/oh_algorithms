class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        x,self.used=[0]*n,[0]*(n+1)     #used[i]表示i是否使用过
        self.cnt=0
        self.dfs(x,0,k)
        ret=""              #将ans转换为字符串ret
        for e in self.ans:ret+=str(e)
        return ret 
    def dfs(self,x,i,k):  #回溯算法
        n=len(x)
        if i>=n:
            self.cnt+=1                          #累计找到的排列个数
            if self.cnt==k:                    #找到第k个排列
                self.ans=x
                return True
        else:
            for j in range(1,n+1):
                if self.used[j]:continue                   #剪支：跳过已经使用过的a[j]
                x[i]=j
                self.used[j]=1                              #选择a[j]
                if self.dfs(x,i+1,k):return True
                self.used[j]=0                              #回溯
                x[i]=-1
        return False
