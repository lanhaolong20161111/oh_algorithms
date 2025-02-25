class Solution:
    def closestKValues(self,root:Optional[TreeNode],target:float,k:int)->List[int]:
        ans,self.a=[],[]
        self.inorder(root)
        high=bisect_left(self.a,target)
        low=high-1
        for i in range(k):
            if low>=0 and high<len(self.a):
                if abs(self.a[low]-target)<=abs(self.a[high]-target):
                    ans.append(self.a[low])
                    low-=1
                else:
                    ans.append(self.a[high])
                    high+=1
            elif low>=0:
                ans.append(self.a[low])
                low-=1
            else:
                ans.append(self.a[high])
                high+=1
        return ans

    def inorder(self,root):                  #中序遍历得到a
        if root:
            self.inorder(root.left)
            self.a.append(root.val)
            self.inorder(root.right)
