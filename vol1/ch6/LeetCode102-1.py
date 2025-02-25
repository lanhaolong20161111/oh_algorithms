from collections import deque
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans=[]
        if root==None:return ans
        qu=deque()      #定义一个队列qu
        qu.append([root,1])              #根结点(层次为1)进队
        curp=[]                             #一层的结点值序列
        curl=1                              #当前层次
        while qu:                    #队不空循环
            e=qu.popleft()           #出队一个结点
            p=e[0]; lev=e[1]
            if p.left!=None:                      #有左孩子时将其进队
                qu.append([p.left,lev+1])
            if p.right!=None:                     #有右孩子时将其进队
                qu.append([p.right,lev+1])
            if lev==curl:                           #出队结点的层次等于curl
                curp.append(p.val)
            else:                                 #分割点：首次遇到层次大于curl的出队结点
                ans.append(curp)                #将上一层结点值序列添加到ans中
                curp=[]
                curp.append(p.val)
                curl+=1
        ans.append(curp)        #将最下一层结点值序列添加到ans中
        return ans
