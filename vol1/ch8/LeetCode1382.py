class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        self.ins=[]
        self.inorder(root)
        return self.preorder(0,len(self.ins)-1); 

    def inorder(self,root):
        if root:
            self.inorder(root.left);
            self.ins.append(root);
            self.inorder(root.right);

    def preorder(self,low,high):
        if low>high: return None
        mid=(low+high)//2
        root=self.ins[mid]
        root.left=self.preorder(low,mid-1)
        root.right=self.preorder(mid+1,high)
        return root
