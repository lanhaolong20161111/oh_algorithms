class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:return None
        lefts=self.invertTree(root.left)
        rights=self.invertTree(root.right)
        root.left,root.right=rights,lefts
        return root
