class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.sum=0
        self.revinorder(root)
        return root
    
    def revinorder(self,root):
        if root!=None:
            self.revinorder(root.right)
            self.sum+=root.val
            root.val=self.sum
            self.revinorder(root.left)
