from collections import deque
class Solution:
    def findNearestRightNode(self, root: TreeNode, u: TreeNode) -> Optional[TreeNode]:
        if root.left==None and root.right==None:
            return None 
        qu=deque()      #定义一个队列qu
        qu.append(root)              #根结点(层次为1)进队
        while qu:                    #队不空循环
            n=len(qu)
            for i in range(0,n):
                p=qu.popleft()           #出队一个结点
                if p==u:
                    if i==n-1:return None
                    else: return qu[0]
                else:
                    if p.left!=None:                      #有左孩子时将其进队
                        qu.append(p.left)
                    if p.right!=None:                     #有右孩子时将其进队
                        qu.append(p.right)
        return None
