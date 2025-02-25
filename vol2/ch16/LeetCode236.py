class Solution:
    def lowestCommonAncestor(self,root:'TreeNode',p:'TreeNode',q:'TreeNode')->'TreeNode':
        if not root:return None
        if root==p or root==q:return root
        leftans=self.lowestCommonAncestor(root.left,p,q)
        rightans=self.lowestCommonAncestor(root.right,p,q)
        if leftans!=None and rightans!=None:
            return root
        elif leftans!=None:
            return leftans
        elif rightans!=None:
            return rightans
        return None
