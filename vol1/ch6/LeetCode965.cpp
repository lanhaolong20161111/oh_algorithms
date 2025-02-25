class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL) return true;
        else return preorder(root,root->val);
    }
    bool preorder(TreeNode*root,int d) {
        if(root==NULL)
            return true;
        else {
            if(root->val!=d) return false;
            bool leftans=preorder(root->left,d);
            if(!leftans) return false;
            else return preorder(root->right,d);
        }
    }
};

