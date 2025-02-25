class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        self.pre=None
        return self.inorder(root)

    def inorder(self,root):      #判断是否为BST
        if root==None:                 #空树是一棵二叉排序树
            return True
        else:
            if not self.inorder(root.left):    #判断左子树
                return False           #若左子树不是BST时返回false
            if self.pre!=None and self.pre.val>=root.val:
                return False           #若当前结点值逆序返回false
            self.pre=root                   #保存当前结点
            return self.inorder(root.right)   #判断右子树，返回其结果
