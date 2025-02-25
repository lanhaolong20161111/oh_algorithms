class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        if root.left==None and root.right==None:       #叶子结点
            return True if root.val==1 else False
        leftans=self.evaluateTree(root.left)
        rightans=self.evaluateTree(root.right)
        if root.val==2:
            return leftans or rightans
        else:
            return leftans and rightans
