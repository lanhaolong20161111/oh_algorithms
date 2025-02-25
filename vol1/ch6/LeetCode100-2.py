class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p==None and q==None:
            return True
        elif p==None or q==None:
            return False
        else:
            prep=self.preorder(p)
            preq=self.preorder(q)
            return prep==preq

    def preorder(self,root):
        pres=""
        if root==None:
            pres="#"
        else:
            pres+=str(root.val)+","            #数字后面添加一个','
            pres+=self.preorder(root.left)                #产生左子树的序列化序列
            pres+=self.preorder(root.right)               #产生右子树的序列化序列
        return pres
