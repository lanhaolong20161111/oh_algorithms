class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.ans=0
        self.depth(root)
        return self.ans

    def depth(self,root):
        if root==None: return 0
        leftdepth=self.depth(root.left)
        rightdepth=self.depth(root.right)
        self.ans=max(self.ans,leftdepth+rightdepth)
        return max(leftdepth,rightdepth)+1
