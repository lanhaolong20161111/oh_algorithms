class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans=[]
        if root==None:return ans
        st=[]                   #用列表st作为栈
        p=root
        while st or p!=None:
            while p!=None:
                ans.append(p.val)
                st.append(p)
                p=p.left
            if st:
                p=st.pop()
                p=p.right
        return ans
