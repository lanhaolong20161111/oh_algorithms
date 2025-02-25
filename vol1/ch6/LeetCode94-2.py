class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans=[]
        if root==None:return ans
        st=[]                   #用列表st作为栈
        p=root
        while st or p!=None:
            while p!=None:
                st.append(p)
                p=p.left
            if st:
                q=st.pop()
                ans.append(q.val)
                p=q.right
        return ans
