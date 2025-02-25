class Solution:
    def buildTree(self, ins: List[int], posts: List[int]) -> Optional[TreeNode]:
        n=len(posts)
        return self.createbt(posts,0,ins,0,n)

    def createbt(self,posts,i,ins,j,n):
        if n<=0: return None
        root=TreeNode(posts[n+i-1])    #创建根结点root
        p=j
        while ins[p]!=posts[n+i-1]: p+=1          #在中序序列中找等于pres[i]的位置p
        k=p-j                              #确定左子树的结点个数为k
        root.left=self.createbt(posts,i,ins,j,k)          #递归构造左子树
        root.right=self.createbt(posts,i+k,ins,p+1,n-k-1)     #递归构造右子树
        return root
