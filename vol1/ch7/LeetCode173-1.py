class BSTIterator:
    def __init__(self, root: Optional[TreeNode]):
        self.curp=-1
        self.nums=[]
        self.inorder(root)

    def inorder(self,root):
        if root!=None:
            self.inorder(root.left)
            self.nums.append(root.val)
            self.inorder(root.right)

    def next(self) -> int:
        self. curp +=1
        x=self.nums[self. curp]
        return x

    def hasNext(self) -> bool:
        return self. curp!=len(self.nums)-1
