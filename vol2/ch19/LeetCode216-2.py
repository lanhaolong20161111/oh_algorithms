class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        x=[-1 for i in range(0,k)]
        self.ans=[]
        self.dfs(n,k,0,x,0);                #i从0开始
        return self.ans
    def dfs(self,n,k,cs,x,i):  #回溯算法
        if i>=k:                        #找到一个叶子结点
            if cs==n:                      #找到一个满足条件的解
                 self.ans.append(copy.deepcopy(x))
        else:                                  #没有到达叶子结点
            for j in range(1,10):
                if i>0 and j<=x[i-1]:continue
                x[i]=j
                self.dfs(n,k,cs+j,x,i+1)
