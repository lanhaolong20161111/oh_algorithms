class Solution {
public:
  int rob(TreeNode* root) {
      if (root==NULL) return 0;
          vector<int> dp=dfs(root);
          return max(dp[0],dp[1]);
      }
      vector<int> dfs(TreeNode* root) {				//Ê÷ÐÍDP
        if (root==NULL) return {0,0};
          vector<int> dp(2,0);
          vector<int> leftdp=dfs(root->left);
          vector<int> rightdp=dfs(root->right);
          dp[0]=max(leftdp[0],leftdp[1])+max(rightdp[0],rightdp[1]);
          dp[1]=root->val+leftdp[0]+rightdp[0];
          return dp;
      }
};

