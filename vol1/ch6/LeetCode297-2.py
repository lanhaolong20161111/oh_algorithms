class Codec:
    def serialize(self, root):      #序列化
        return self.preorder(root)

    def preorder(self,root):
        pres=""
        if root==None:
            pres="#"
        else:
            pres+=str(root.val)+","               #数字后面添加一个','
            pres+=self.preorder(root.left)               #产生左子树的序列化序列
            pres+=self.preorder(root.right)              #产生右子树的序列化序列
        return pres

    def deserialize(self, data):   #反序列化
        self.i=0
        return self.createbt(data)

    def createbt(self,data):
        if self.i>=len(data): return None
        if data[self.i]=='#':
            self.i+=1
            return None
        root=TreeNode(self.getval(data))
        root.left=self.createbt(data)
        root.right=self.createbt(data)
        return root

    def getval(self,s):       #数字串转换为整数
        d,flag=0,1
        while self.i<len(s) and s[self.i]!=',':
            if s[self.i]=='-':
                flag,self.i=-1,self.i+1
            else:
                d=d*10+int(s[self.i])
                self.i+=1
        self.i+=1                    #通过数字串结尾的','
        return flag*d
