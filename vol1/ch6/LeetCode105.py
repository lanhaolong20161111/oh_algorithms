class Solution:
    def buildTree(self, pres: List[int], ins: List[int]) -> Optional[TreeNode]:
        n=len(pres)
        return self.createbt(pres,0,ins,0,n)

    def createbt(self,pres,i,ins,j,n):
        if n<=0: return None
        root=TreeNode(pres[i])    #创建根结点root
        p=j
        while ins[p]!=pres[i]: p+=1          #在中序序列中找等于pres[i]的位置p
        k=p-j                              #确定左子树的结点个数为k
        root.left=self.createbt(pres,i+1,ins,j,k)          #递归构造左子树
        root.right=self.createbt(pres,i+k+1,ins,p+1,n-k-1)     #递归构造右子树
        return root
