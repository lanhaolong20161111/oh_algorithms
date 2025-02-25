class Solution:
    def splitBST(self, root:Optional[TreeNode],target:int)->List[Optional[TreeNode]]:
        if root==None:
            return [None,None]
        elif root.val<=target:
            tmp=self.splitBST(root.right,target)
            root.right=tmp[0]
            return [root,tmp[1]]
        else:
            tmp=self.splitBST(root.left,target)
            root.left=tmp[1]
            return [tmp[0],root] 
