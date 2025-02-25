class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode*s=new TreeNode(val);
        if(root==NULL) return s;
        if(val<root->val) root->left=insertIntoBST(root->left,val);
        else root->right=insertIntoBST(root->right,val);
        return root;
    }
};

