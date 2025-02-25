class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.ans=[]
        self.inorder(root)
        return self.ans

    def inorder(self,root):							#递归中序遍历算法
        if root!=None:
            self.inorder(root.left)
            self.ans.append(root.val)
            self.inorder(root.right)
