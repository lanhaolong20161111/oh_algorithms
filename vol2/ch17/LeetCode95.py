class Solution:
    def generateTrees(self, n: int)->List[Optional[TreeNode]]:
        if n==0: return []
        else: return self.generate(1,n)
    def generate(self,low,high):
        ans=[]
        if low>high:                        #空区间
            ans.append(None)                    #构造空树
            return ans
        for i in range(low,high+1):             #枚举根结点
            leftbst=self.generate(low,i-1)      #构造左子树集合
            rightbst=self.generate(i+1,high)    #构造右子树集合
            for l in leftbst:                    #拼接
                for r in rightbst:
                    b=TreeNode(i)           #构造根结点b
                    b.left,b.right=l,r
                    ans.append(b)
        return ans
