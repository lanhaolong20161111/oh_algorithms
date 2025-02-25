class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *ans=NULL;
        if (p->right!=NULL) {
            ans=p->right;
            while(ans->left !=NULL) ans=ans->left;
            return ans;
        }
        else {
            ans=NULL;
            while (root!=NULL) {
                if(root->val>p->val) {					//仅考虑大于结点p的结点
                    if(ans==NULL) ans=root;								//第一个大于结点p的结点
                    else if(root->val-p->val<ans->val-p->val) ans=root; 	//大于结点p且更接近结点p的结点
                }
                if (p->val<root->val)  root=root->left;
                else root=root->right;
            }
            return ans;
        }
    }
};

