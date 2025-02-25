from collections import deque
class Solution:
    def closestKValues(self,root:Optional[TreeNode],target:float,k:int)->List[int]:
        self.qu=deque()             #作为队列
        self.inorder(root,target,k)
        return list(self.qu)

    def inorder(self,root,target,k):
        if root:
            self.inorder(root.left,target,k)
            if len(self.qu)==k:
                if abs(self.qu[0]-target)>abs(root.val-target):
                    self.qu.popleft()
                    self.qu.append(root.val)
                else: return
            else: self.qu.append(root.val)
            self.inorder(root.right,target,k)
