class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.cnt=0
        self.inorder(root,k)
        return self.ans

    def inorder(self,root,k):
        if root==None: return False
        if self.inorder(root.left,k): return True
        self.cnt+=1
        if self.cnt==k:
            self.ans=root.val
            return True
        return self.inorder(root.right,k)
