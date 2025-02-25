from collections import deque
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ans=[]
        if root==None:return ans
        qu=deque()      #定义一个队列qu
        qu.append([root,1])              #根结点(层次为1)进队
        pre,p=None,None
        curl=1                              #当前层次
        while qu:                    #队不空循环
            pre=p                       #保存结点p的前一个访问的结点
            e=qu.popleft()        #出队一个结点
            p=e[0]; lev=e[1]
            if p.left!=None:                      #有左孩子时将其进队
                qu.append([p.left,lev+1])
            if p.right!=None:                     #有右孩子时将其进队
                qu.append([p.right,lev+1])
            if lev>curl:                           #分割点：当前结点p为curl+1层的首结点
                ans.append(pre.val)             #将curl层的最后一个结点值添加到ans中
                curl+=1
        ans.append(p.val)           #最下一层最右结点是结点p
        return ans
