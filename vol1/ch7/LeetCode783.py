class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        self.ans=100005
        self.pre=None
        self.inorder(root)
        return self.ans

    def inorder(self,root):
        if root:
            self.inorder(root.left)
            if self.pre!=None:self.ans=min(self.ans,abs(root.val-self.pre.val))
            self.pre=root
            self.inorder(root.right)
