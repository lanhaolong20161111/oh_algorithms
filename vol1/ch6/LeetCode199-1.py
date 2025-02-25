class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        self.ans=[]                 #存放求解结果
        if root==None: return self.ans
        self.preorder(root,0)
        return self.ans

    def preorder(self,root,h):
        if root==None: return
        if h==len(self.ans):            #保证第h层只向ans中添加第一个访问结点
            self.ans.append(root.val)
        else:                        #第h层的其他结点覆盖之前的结点
            self.ans[h]=root.val
        self.preorder(root.left,h+1)
        self.preorder(root.right,h+1)
