class Solution:
    def wordBreak(self, s:str,wordDict:List[str])->List[str]:
        n=len(s)
        hset=set()
        for e in wordDict:hset.add(e)
        dp=[[] for _ in range(0,n+2)]
        dp[0].append(0)
        for i in range(1,n+1):
            for j in range(0,i):
                w=s[j:i]
                if dp[j] and w in hset:
                    dp[i].append(j)
        if len(dp[n])==0: return []
        self.ans=[]
        path=[]
        self.dfs(s,path,dp,n)
        return self.ans
    def dfs(self,s,path,dp,i):      #i为s的前缀长度
        if i==0:
            tmp=path[-1]    #由path反向串起来构成一个解tmp
            for k in range(len(path)-2,-1,-1):
                tmp+=" "
                tmp+=path[k]
            self.ans.append(tmp)
        else:
            for j in dp[i]: 
                w=s[j:i]        #s[j..i-1]一定是单词
                path.append(w)
                self.dfs(s,path,dp,j)
                path.pop()
