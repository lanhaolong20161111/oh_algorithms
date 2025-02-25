class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        self.ans=[];        #存放nums的全排列
        x=nums
        self.dfs(x,0)
        return self.ans
    def dfs(self,x,i):      #回溯算法
        if i==len(x):
            self.ans.append(list(x))
        else:
            for j in range(i,len(x)):
                if self.judge(x,i,j):continue      #检测x[j]
                x[i],x[j]=x[j],x[i]
                self.dfs(x,i+1)
                x[i],x[j]=x[j],x[i]
    def judge(self,x,i,j):          #判断x[j]是否出现在x[i..j-1]中
        if j>i:
            for k in range(i,j):                #x[j]是否与x[i..j-1]的元素相同 
                if x[k]==x[j]:return True       #若相同则返回真
        return False                            #全部不相同返回假
