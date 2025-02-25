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
            p=pre;										//p为空且找到前面的逆序结点pre，则置p为pre
        if(p!=NULL && pre->val>root->val)
            q=root;									//p不为空且当前结点逆序，则置q为root
        pre=root;
        inorder(root->right);
    }
};

