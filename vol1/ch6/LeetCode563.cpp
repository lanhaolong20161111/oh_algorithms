class Solution {
    int ans;
public:
    int findTilt(TreeNode* root) {
        ans=0;
        sum(root);
        return ans;
    }

    int sum(TreeNode*root) {
        if(root==NULL) return 0;
        int leftsum=sum(root->left);
        int rightsum=sum(root->right);
        ans+=abs(leftsum-rightsum);
        return root->val+leftsum+rightsum;
    }
};

