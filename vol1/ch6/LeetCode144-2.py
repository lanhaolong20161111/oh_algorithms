class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans=[]
        if root==None:return ans
        st=[]                   #用列表st作为栈
        st.append(root)
        while st:
            p=st.pop()
            ans.append(p.val)
            if p.right!=None:      #结点p存在右子树时将其进栈
                st.append(p.right)
            if p.left!=None:       #结点p存在左子树时将其进栈
                st.append(p.left)
        return ans
