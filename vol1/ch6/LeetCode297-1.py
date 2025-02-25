from collections import deque
class Codec:    
    def serialize(self, root):					#序列化
        s=""
        if root==None:return s
        qu=deque()                            #定义一个队列qu
        qu.append(root)                                  #根结点进队 
        while qu:                          #队不空循环
            p=qu.popleft()           #出队一个结点
            if p!=None:  
                s+=str(p.val)+","               #数字后面添加一个','
                qu.append(p.left)                       #左孩子进队（含空的左孩子）
                qu.append(p.right)                      #右孩子进队（含空的右孩子）
            else: s+="#"                           #结点p为空，添加外部结点值
        return s

    def deserialize(self, data):					#反序列化
        n=len(data)
        if n==0:return None;
        self.i=0                                          #用属性i遍历s
        qu=deque()                                #定义一个队列qu
        root=TreeNode(self.getval(data));                          #创建根结点 
        qu.append(root)                      #根结点进队 
        while  qu:       #队不空循环：每次循环访问一层结点
            m=len(qu)                                        #求队中元素个数m
            for j in range(0,m):                         #出队该层的m个结点
                p=qu.popleft()           #出队一个结点
                if self.i<n and data[self.i]!='#':                        #结点p存在左孩子
                    p.left=TreeNode(self.getval(data))           #创建结点p的左孩子
                    qu.append(p.left)                               #左孩子进队
                else:                  #data[i]=null
                    p.left=None                   #否则置结点p的左孩子为空
                    self.i+=1
                if self.i<n and data[self.i]!='#':                    #结点p存在右孩子 
                    p.right=TreeNode(self.getval(data))      #创建结点p的右孩子
                    qu.append(p.right)                          #右孩子进队
                else:                      #data[i]=null
                    p.right=None          #否则置结点p的右孩子为空
                    self.i+=1
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
