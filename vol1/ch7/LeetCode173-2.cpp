class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushleft(root);
    }
    
    int next() {
        TreeNode*p=st.top(); st.pop();
        pushleft(p->right);
        return p->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    void pushleft(TreeNode*p) {
        while(p!=NULL) {
            st.push(p);
            p=p->left;
        }
    }
};

