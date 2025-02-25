class Solution:
    def isUnivalTree(self, root: Optional[TreeNode]) -> bool:
        if root==None:return True
        else: return self.preorder(root,root.val)

    def preorder(self,root,d):
        if root==None:
            return True
        else:
            if root.val!=d:return False
            leftans=self.preorder(root.left,d)
            if not leftans: return False
            else: return self.preorder(root.right,d)
