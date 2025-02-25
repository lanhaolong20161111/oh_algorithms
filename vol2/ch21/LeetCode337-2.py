class Solution:
  def rob(self, root: Optional[TreeNode]) -> int:
    if not root:return 0
    dp=self.dfs(root)
    return max(dp[0],dp[1])
  def dfs(self,root):							#树型DP
    if not root:return [0,0]
    dp=[0,0]
    leftdp=self.dfs(root.left)
    rightdp=self.dfs(root.right)
    dp[0]=max(leftdp[0],leftdp[1])+max(rightdp[0],rightdp[1])
    dp[1]=root.val+leftdp[0]+rightdp[0]
    return dp
