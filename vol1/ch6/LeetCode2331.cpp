class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)   //Ҷ�ӽ��
            return root->val==1?true:false;
        bool leftans=evaluateTree(root->left);
        bool rightans=evaluateTree(root->right);
        if(root->val==2)
            return leftans | rightans;
        else
            return leftans & rightans; 
    }
};

