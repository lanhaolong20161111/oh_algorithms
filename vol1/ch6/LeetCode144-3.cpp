class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        TreeNode*p=root;
        while (!st.empty() || p!=NULL) {
            while(p!=NULL) {
                ans.push_back(p->val);
                st.push(p);
                p=p->left;
            }
            if(!st.empty()) {
                p=st.top(); st.pop();
                p=p->right;
            }
        }
        return ans;
    }
};

