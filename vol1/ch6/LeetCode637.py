from collections import deque
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        ans=[]
        qu=deque()      #定义一个队列qu
        qu.append(root)              #根结点(层次为1)进队
        while qu:                    #队不空循环
            n=len(qu)
            cursum=0.0
            for i in range(0,n):
                p=qu.popleft()           #出队一个结点
                cursum+=p.val                 #当前层的结点值累计到cursum
                if p.left!=None:                      #有左孩子时将其进队
                    qu.append(p.left)
                if p.right!=None:                     #有右孩子时将其进队
                    qu.append(p.right)
            ans.append(cursum/n)
        return ans
