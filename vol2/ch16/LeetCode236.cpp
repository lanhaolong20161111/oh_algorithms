class Solution {
public:
    TreeNode*lowestCommonAncestor(TreeNode*root,TreeNode*p,TreeNode*q) {
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;
        TreeNode*leftans=lowestCommonAncestor(root->left,p,q);
        TreeNode*rightans=lowestCommonAncestor(root->right,p,q);
        if(leftans!=NULL && rightans!=NULL)
            return root;
        else if(leftans!=NULL)
            return leftans;
        else if(rightans!=NULL)
            return rightans;
        return NULL;
    }
};

