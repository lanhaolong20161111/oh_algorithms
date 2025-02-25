class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        preroot=self.preorder(root)
        presubroot=self.preorder(subRoot)
        i=preroot.find(presubroot)
        print(preroot)
        print(presubroot)
        if i!=-1 and (i==0 or preroot[i-1]=='#' or preroot[i-1]==','):
            return True
        else:
            return False
    
    def preorder(self,root):
        pres=""
        if root==None:
            pres="#"
        else:
            pres+=str(root.val)+","            #数字后面添加一个','
            pres+=self.preorder(root.left)                #产生左子树的序列化序列
            pres+=self.preorder(root.right)               #产生右子树的序列化序列
        return pres
