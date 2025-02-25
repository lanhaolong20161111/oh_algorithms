class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        ans=[]
        n=len(expression)
        if n==1 or n==2:
            ans.append(int(expression))
            return ans
        for i in range(0,n):
            c=expression[i]
            if c=='+' or c=='-' or c=='*':
                lefts=self.diffWaysToCompute(expression[0:i])
                rights=self.diffWaysToCompute(expression[i+1:])
                for l in lefts:         #将组合结果通过运算符组合
                    for r in rights:
                        if c=='+': ans.append(l+r)
                        elif c=='-': ans.append(l-r)
                        elif c=='*': ans.append(l*r)
        return ans          #返回合并后的结果
