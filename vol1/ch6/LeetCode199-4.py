from collections import deque
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ans=[]
        if root==None:return ans
        qu=deque()      #定义一个队列qu
        qu.append(root)              #根结点(层次为1)进队
        while qu:                    #队不空循环
            n=len(qu)
            for i in range(0,n):
                p=qu.popleft()           #出队一个结点
                if i==n-1:ans.append(p.val)         #当前层最右结点值添加到ans
                if p.left!=None:                      #有左孩子时将其进队
                    qu.append(p.left)
                if p.right!=None:                     #有右孩子时将其进队
                    qu.append(p.right)
        return ans
