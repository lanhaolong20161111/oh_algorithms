class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.ans=[]
        self.preorder(root)
        return self.ans

    def preorder(self,root):								#递归先序遍历算法
        if root!=None:
            self.ans.append(root.val)
            self.preorder(root.left)
            self.preorder(root.right)
