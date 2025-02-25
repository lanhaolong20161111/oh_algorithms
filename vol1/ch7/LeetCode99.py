class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        self.p,self.q,self.pre=None,None,None
        self.inorder(root)
        if self.p!=None and self.q!=None:
            self.p.val,self.q.val=self.q.val,self.p.val

    def inorder(self,root):
        if root==None: return
        self.inorder(root.left)
        if self.pre!=None and self.p==None and self.pre.val>root.val:
            self.p=self.pre
        if self.p!=None and self.pre.val>root.val:
            self.q=root
        self.pre=root
        self.inorder(root.right)
