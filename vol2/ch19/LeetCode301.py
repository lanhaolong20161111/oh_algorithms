class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        self.ans=[]
        left,right=0,0
        for e in s:
            if e=='(': left+=1      #累计左括号数
            elif e==')':
                if left==0:right+=1   #不匹配的右括号数增加1
                else: left-=1            #不匹配的左括号数减少1
        self.dfs(s,0,left,right)
        return self.ans
    def dfs(self,s,j,left,right):   #回溯算法
        if left==0 and right==0:         #找到一个解
            if self.valid(s):self.ans.append(str(s))
        else:
            for j1 in range(j,len(s)):				# j1从j到n-1循环
                if j1>j and s[j1]==s[j1-1]:    #去重
                    continue
                if left>0 and s[j1]=='(':   #尝试去掉一个左括号
                    self.dfs(s[0:j1]+s[j1+1:],j1,left-1,right)
                if right>0 and s[j1]==')':   #尝试去掉一个右括号
                    self.dfs(s[0:j1]+s[j1+1:],j1,left,right-1)
    def valid(self,s):                    #判断s中的括号是否匹配
        cnt=0
        for e in s:
            if e=='(':cnt+=1
            elif e==')':
                cnt-=1
                if cnt<0:return False
        return True if cnt==0 else False
