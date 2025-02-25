class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int ans=root->val;
        while(root!=NULL) {
            if(abs(root->val-target)<abs(ans-target))  ans=root->val;
            if(target<root->val) root=root->left;
            else root=root->right;
        }
        return ans;
    }
};

