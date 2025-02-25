class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if root==None:
            return False
        if self.same(root,subRoot):
            return True
        if self.isSubtree(root.left,subRoot):
            return True
        elif self.isSubtree(root.right,subRoot):
            return True
        else:
            return False

    def same(self,r1,r2):    #判断r1和r2两棵二叉树是否相同
        if r1==None and r2==None:
            return True 
        if r1==None or r2==None:
            return False
        if r1.val!=r2.val:
            return False
        return self.same(r1.left,r2.left) and self.same(r1.right,r2.right)
