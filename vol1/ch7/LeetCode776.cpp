class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root,int target) {
        if(root==NULL)
            return {NULL,NULL};
        else if (root->val<=target) {
            vector<TreeNode*> tmp=splitBST(root->right,target);
            root->right=tmp[0];
            return {root,tmp[1]};
        }
        else {
            vector<TreeNode*> tmp=splitBST(root->left,target);
            root->left=tmp[1];
            return {tmp[0],root};
        }
    }
};

