class Solution {
    int ans;                //存放答案
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        depth(root);
        return ans;
    }
    int depth(TreeNode* root) {
        if(root==NULL) return 0;
        int leftd=depth(root->left);
        int rightd=depth(root->right);
        ans=max(ans,leftd+rightd);  //每个结点的等于左子树深度+右子树深度
        return max(leftd,rightd)+1;//返回结点r的深度
    }
};

