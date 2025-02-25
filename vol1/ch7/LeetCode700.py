class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root==None:return None
        if root.val==val:return root
        elif val<root.val:return self.searchBST(root.left,val)
        else: return self.searchBST(root.right,val)
