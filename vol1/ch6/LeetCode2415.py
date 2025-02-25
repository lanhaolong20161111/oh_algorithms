from collections import deque
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root.left==None and root.right==None:
            return root 
        qu=deque()      #定义一个队列qu
        qu.append(root)              #根结点(层次为1)进队
        curl=0
        while qu:                    #队不空循环
            n=len(qu)
            curp=[]
            for i in range(0,n):
                p=qu.popleft()           #出队一个结点
                curp.append(p)                 #当前层的结点值添加到curp
                if p.left!=None:                      #有左孩子时将其进队
                    qu.append(p.left)
                if p.right!=None:                     #有右孩子时将其进队
                    qu.append(p.right)
            if curl%2==1: self.rev(curp)
            curl+=1
        return root

    def rev(self,a):							#反转a
        i,j=0,len(a)-1
        while i<j:
            tmp=a[i].val					#注意应该采用传统交换方式
            a[i].val=a[j].val
            a[j].val=tmp
            i+=1; j-=1
