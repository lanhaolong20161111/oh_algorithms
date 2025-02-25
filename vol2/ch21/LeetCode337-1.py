class Solution:
  def rob(self, root: Optional[TreeNode]) -> int:
    self.hmap={}
    if root==None:return 0
    return self.dfs(root)
  def dfs(self,root):
    if not root:return 0
    if root in self.hmap: #该子问题已经求出，直接返回解
      return self.hmap[root]
    money1=root.val
    if root.left!=None:
      money1+=self.dfs(root.left.left)+self.dfs(root.left.right)
    if root.right!=None:
      money1+=self.dfs(root.right.left)+self.dfs(root.right.right)
    money2=self.dfs(root.left)+self.dfs(root.right)
    self.hmap[root]=max(money1,money2)
    return self.hmap[root]
