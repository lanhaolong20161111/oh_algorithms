class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;                     //空树直接返回
        flatten(root->left);
        flatten(root->right);
        TreeNode *tmp=root->right;                 //临时存放单链表B的首结点
        root->right=root->left;
        root->left=NULL;
        TreeNode* p=root;
        while(p->right!=NULL)                   //找到单链表A的尾结点p
            p=p->right;
        p->right=tmp;                           //链接起来
    }
};

