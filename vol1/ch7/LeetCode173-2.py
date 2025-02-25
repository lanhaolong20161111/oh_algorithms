class BSTIterator:
    def __init__(self, root: Optional[TreeNode]):
        self.curp=root
        self.st=[]               #作为一个栈

    def next(self) -> int:
        while self.curp!=None:
            self.st.append(self.curp)
            self.curp=self.curp.left
        self.curp=self.st.pop()
        curpval=self.curp.val        #访问curp
        self.curp=self.curp.right
        return curpval

    def hasNext(self) -> bool:
         return self.curp!=None or len(self.st)>0
