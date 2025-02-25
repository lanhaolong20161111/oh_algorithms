class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        self.ans=0
        self.sum(root)
        return self.ans
    
    def sum(self,root):
        if root==None:return 0
        leftsum=self.sum(root.left)
        rightsum=self.sum(root.right)
        self.ans+=abs(leftsum-rightsum)
        return root.val+leftsum+rightsum
