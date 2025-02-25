class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return Sum(root,low,high);
    }
    int Sum(TreeNode* root,int low,int high)  {
	if(root==NULL)  return 0;
        if(root->val<low)                       //�����ֵ<low�����������Ľ�㶼����������
            return Sum(root->right,low,high);
        else if(root->val>high)                         //�����ֵ>high�����������Ľ�㶼����������
            return Sum(root->left,low,high);
        else {
        int lsum=Sum(root->left,low,high);          //��root�����
        int rsum=Sum(root->right,low,high);
        return root->val+lsum+rsum;
    }
}
};

