class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p==None and q==None: return True
        elif p==None or q==None: return False
        elif p.val!=q.val: return False
        else: return self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right)
