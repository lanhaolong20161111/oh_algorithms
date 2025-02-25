class Solution {
    const int INF=0x3f3f3f3f;
    int ans;
public:
    int maxPathSum(TreeNode* root) {
        ans=-INF;
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root) {				//Ê÷ÐÍDP
        if(root==NULL) return 0;
        int leftlen=dfs(root->left);
        int rightlen=dfs(root->right);
        ans=max(ans,root->val+leftlen+rightlen);
        return max(0,max(root->val+leftlen,root->val+rightlen));
    }
};

