class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode*p=root;
        while(!st.empty() || p!=NULL) {
            while(p!=NULL) {
                st.push(p);
                p=p->left;
            }
            if(!st.empty()) {
                TreeNode*q=st.top(); st.pop();
                ans.push_back(q->val);
                p=q->right;
            }
        }
        return ans;
    }
};

