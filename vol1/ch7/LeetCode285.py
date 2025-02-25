class Solution:
    def inorderSuccessor(self, root: TreeNode, p: TreeNode) -> Optional[TreeNode]:
        ans=None
        if p.right!=None:
            ans=p.right
            while ans.left!=None:
                ans=ans.left
            return ans
        else:
            while root!=None:
                if p.val<root.val:
                    ans=root
                    root=root.left
                else: root=root.right
            return ans
