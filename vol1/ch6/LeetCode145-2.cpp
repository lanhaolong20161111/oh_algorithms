class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode*p=st.top(); st.pop();
            ans.push_back(p->val);
            if(p->left!=NULL)       //结点p存在右子树时将其进栈
                st.push(p->left);
            if(p->right!=NULL)      //结点p存在左子树时将其进栈
                st.push(p->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

