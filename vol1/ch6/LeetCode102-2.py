from collections import deque
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans=[]
        if root==None:return ans
        qu=deque()      #定义一个队列qu
        qu.append(root)              #根结点(层次为1)进队
        last=root
        curl=1                              #当前层次
        curp=[]                             #一层的结点值序列
        q=None
        while qu:                    #队不空循环
            p=qu.popleft()           #出队一个结点
            if p.left!=None:                      #有左孩子时将其进队
                q=p.left
                qu.append(q)
            if p.right!=None:                     #有右孩子时将其进队
                q=p.right
                qu.append(q)
            curp.append(p.val)                 #当前层的结点值添加到curp
            if p==last:                          #当前层的所有结点处理完毕
                ans.append(curp)                #将当前层结点值序列添加到ans中
                last=q                             #让last指向下一层的最右结点
                curp=[]                       #清空curp
                curl+=1                             #进入下一层
        return ans
