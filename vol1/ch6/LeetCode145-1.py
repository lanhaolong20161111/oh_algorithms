class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.ans=[]
        self.postorder(root)
        return self.ans

    def postorder(self,root):									递归后序遍历算法
        if root!=None:
            self.postorder(root.left)
            self.postorder(root.right)
            self.ans.append(root.val)
