class Solution:
    def minimumTimeRequired(self,jobs:List[int],k:int) -> int:
        INF=0x3f3f3f3f
        self.ans=INF
        jobs.sort(reverse=True)
        self.jobs=jobs
        self.k=k
        self.times=[0]*k
        self.dfs(0,0)
        return self.ans
    def dfs(self,ct,i):    #回溯算法
        if i==len(self.jobs):
            self.ans=ct
        else:
            flag=True             #前面没有空闲工人时为true
            for j in range(0,self.k):
                if self.times[j]==0:
                    if not flag:return       #剪支1：前面有空闲工人时跳过
                    flag=False             #前面有空闲工人时置为false
                self.times[j]+=self.jobs[i]          #工作i分配给工人j
                curtime=max(ct,self.times[j])   #剪支2
                if curtime<=self.ans:
                    self.dfs(curtime,i+1)
                self.times[j]-=self.jobs[i]              #回溯
