class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        return self.Sum(root,low,high)

    def Sum(self,root,low,high):
        if root==None: return 0
        if root.val<low:    #根结点值<low，满足条件的结点都在右子树中
            return self.Sum(root.right,low,high)
        elif root.val>high:                         #根结点值>high，满足条件的结点都在左子树中
            return self.Sum(root.left,low,high)
        else:
            lsum=self.Sum(root.left,low,high);          #含root根结点
            rsum=self.Sum(root.right,low,high)
            return root.val+lsum+rsum
