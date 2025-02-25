class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return Sum(root,low,high);
    }
    int Sum(TreeNode* root,int low,int high)  {
	if(root==NULL)  return 0;
        if(root->val<low)                       //根结点值<low，满足条件的结点都在右子树中
            return Sum(root->right,low,high);
        else if(root->val>high)                         //根结点值>high，满足条件的结点都在左子树中
            return Sum(root->left,low,high);
        else {
        int lsum=Sum(root->left,low,high);          //含root根结点
        int rsum=Sum(root->right,low,high);
        return root->val+lsum+rsum;
    }
}
};

