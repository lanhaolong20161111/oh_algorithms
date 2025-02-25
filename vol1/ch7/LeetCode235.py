class Solution:
    def lowestCommonAncestor(self,root:'TreeNode',p:'TreeNode',q:'TreeNode')->'TreeNode':
        if root==None: return None
        while root!=None:
            if p.val<root.val and q.val<root.val: root=root.left
            elif p.val>root.val and q.val>root.val: root=root.right
            else: return root
