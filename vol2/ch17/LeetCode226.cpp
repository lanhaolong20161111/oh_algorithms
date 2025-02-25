class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL) return NULL;
        TreeNode*lefts=invertTree(root->left);
        TreeNode*rights=invertTree(root->right);
        root->left=rights;              //�ϲ�
        root->right=lefts;
        return root;
    }
};

