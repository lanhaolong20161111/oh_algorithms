from collections import deque
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ans=[]
        if root==None:return ans
        qu=deque()      #定义一个队列qu
        qu.append(root)              #根结点(层次为1)进队
        last=root
        q=None
        while qu:                    #队不空循环
            p=qu.popleft()           #出队一个结点
            if p.left!=None:                      #有左孩子时将其进队
                q=p.left
                qu.append(q)
            if p.right!=None:                     #有右孩子时将其进队
                q=p.right
                qu.append(q)
            if p==last:                    #分割点：当前层的所有结点处理完毕
                ans.append(last.val)
                last=q                     #last指向下一层的最右结点
        return ans
