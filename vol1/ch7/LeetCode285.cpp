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
                if(root->val>p->val) {					//�����Ǵ��ڽ��p�Ľ��
                    if(ans==NULL) ans=root;								//��һ�����ڽ��p�Ľ��
                    else if(root->val-p->val<ans->val-p->val) ans=root; 	//���ڽ��p�Ҹ��ӽ����p�Ľ��
                }
                if (p->val<root->val)  root=root->left;
                else root=root->right;
            }
            return ans;
        }
    }
};

