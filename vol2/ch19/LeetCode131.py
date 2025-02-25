class Solution:
    def partition(self, s: str) -> List[List[str]]:
        self.ans,self.x=[],[]
        self.dfs(s,0)
        return self.ans
    def dfs(self,s,j):                                #回溯算法
        if j>=len(s):                                           #找到一个解
            self.ans.append(copy.deepcopy(self.x))
        else:
            for j1 in range(j,len(s)):               #试探i开始的每一个位置j
                s1=s[j:j1+1]               #求出s[j..j1]的子串s1
                if self.isPalindrome(s1):                        #若s1是回文
                    self.x.append(s1)
                    self.dfs(s,j1+1)
                    self.x.pop()                      #回溯
    def isPalindrome(self,s):				#判断s是否为回文
        i,j=0,len(s)-1
        while i<j:
            if s[i]!=s[j]:
                return False
            i,j=i+1,j-1
        return True
