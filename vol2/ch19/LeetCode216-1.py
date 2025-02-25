class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        cnt=0
        self.ans,x=[],[]
        self.dfs(n,k,0,x,cnt,1)                         #i从1开始
        return self.ans
    def dfs(self,n,k,cs,x,cnt,i):     #回溯算法
        if i>=10:                                       #找到一个叶子结点
            if cs==n and cnt==k:                        #找到一个满足条件的解
                self.ans.append(copy.deepcopy(x))
        else:                                  #没有到达叶子结点
            x.append(i)                     #选取整数i 
            cnt+=1
            self.dfs(n,k,cs+i,x,cnt,i+1)
            cnt-=1                              #回溯
            x.pop()
            self.dfs(n,k,cs,x,cnt,i+1)                  #不选取整数i
