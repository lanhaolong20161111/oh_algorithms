class Solution {
    int ans;
    TreeNode*pre;
public:
    int minDiffInBST(TreeNode* root) {
        ans=100005;
        pre=NULL;
        inorder(root);
        return ans;
    }

    void inorder(TreeNode*root) {
        if(root!=NULL) {
            inorder(root->left);
            if(pre!=NULL) ans=min(ans,abs(root->val-pre->val));
            pre=root;
            inorder(root->right);
        }
    }
};

