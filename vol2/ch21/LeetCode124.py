class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.ans=-0x3f3f3f3f
        self.dfs(root)
        return self.ans
    def dfs(self,root):					#树型DP
        if root==None:return 0
        leftlen=self.dfs(root.left)
        rightlen=self.dfs(root.right)
        self.ans=max(self.ans,root.val+leftlen+rightlen)
        return max(0,max(root.val+leftlen,root.val+rightlen))
