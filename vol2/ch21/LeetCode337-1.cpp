class Solution {
  unordered_map<TreeNode*,int> hmap;
public:
  int rob(TreeNode* root) {
    if (root==NULL) return 0;
          return dfs(root);
      }
      int dfs(TreeNode* root) {
        if (root==NULL) return 0;
          if(hmap.find(root)!=hmap.end())     //该子问题已经求出，直接返回解
              return hmap[root];
          int money1=root->val;
          if (root->left!=NULL)
              money1+=dfs(root->left->left)+dfs(root->left->right);
          if (root->right!=NULL)
              money1+=dfs(root->right->left)+dfs(root->right->right);
          int money2=dfs(root->left)+dfs(root->right);
          hmap[root]=max(money1,money2);
          return hmap[root];
      }
};

