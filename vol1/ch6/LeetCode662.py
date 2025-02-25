class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.first,self.last=[],[]
        self.preorder(root,0,0)      #根结点编号从0开始
        ans=0
        for i in range(0,len(self.first)):
            curw=self.last[i]-self.first[i]+1            #求每一层的宽度
            ans=max(ans,curw)              #求树的宽度
        return ans

    def preorder(self,root,h,no):     #先序遍历求first和last
        if root==None: return;
        if len(self.first)==h:                #首次访问第h层的结点
            self.first.append(no)            #将首结点编号添加到first中
        if len(self.last)==h:                  #首次访问第h层的结点
            self.last.append(no)             #将首结点编号添加到first中
        else:                                #访问第h层的其他结点
            self.last[h]=no                 #后者覆盖前者,最后存放第h层最右结点编号
        self.preorder(root.left,h+1,2*no+1)
        self.preorder(root.right,h+1,2*no+2)
