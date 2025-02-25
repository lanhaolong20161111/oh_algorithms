class Solution {
    TreeNode*p,*q,*pre;
public:
    void recoverTree(TreeNode* root) {
        pre=p=q=NULL;
        inorder(root);
        if(p!=NULL) swap(p->val,q->val);
    }
    void inorder(TreeNode*root) {
        if(root==NULL) return;
        inorder(root->left);
        if(pre!=NULL && p==NULL && pre->val>root->val)
            p=pre;										//pΪ�����ҵ�ǰ���������pre������pΪpre
        if(p!=NULL && pre->val>root->val)
            q=root;									//p��Ϊ���ҵ�ǰ�����������qΪroot
        pre=root;
        inorder(root->right);
    }
};

