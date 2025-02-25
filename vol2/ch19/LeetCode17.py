class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        n=len(digits)
        if n==0:return []
        self.hmap={'2':"abc",'3':"def",'4':"ghi",'5':"jkl",'6':"mno",'7':"pqrs",'8':"tuv",'9':"wxyz"}    #映射表
        self.ans,x=[],[]
        self.dfs(digits,x,0)
        return self.ans
    def dfs(self,digits,x,i):       #回溯算法
        if i>=len(digits):
            self.ans.append(''.join(x))
        else:
            key=self.hmap[digits[i]]      #获取映射字母
            for j in range(0,len(key)):
                x.append(key[j])
                self.dfs(digits,x,i+1)
                x.pop()          #回溯
