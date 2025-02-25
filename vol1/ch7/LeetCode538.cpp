class Solution {
    int sum;
public:
    TreeNode* convertBST(TreeNode* root) {
        sum=0;
        revinorder(root);
        return root;
    }

    void revinorder(TreeNode* root) {
        if(root!=NULL) {
	        revinorder(root->right);
     	   sum+=root->val;
        		root->val=sum;
        	revinorder(root->left);
		}
    }
};

