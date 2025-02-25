class Solution {
    int cnt;
    int ans;
public:
    int kthSmallest(TreeNode* root,int k) {
        cnt=0;
        inorder(root,k);
        return ans;

    }
    bool inorder(TreeNode*root,int k) {
        if(root==NULL) return false;
        if(inorder(root->left,k)) return true;
        cnt++;
        if(cnt==k) {
            ans=root->val;
            return true;
        }
        return inorder(root->right,k);
    }
};

