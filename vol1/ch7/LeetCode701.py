class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        s=TreeNode(val)
        if root==None:return s
        if val<root.val:root.left=self.insertIntoBST(root.left,val)
        else: root.right=self.insertIntoBST(root.right,val)
        return root
