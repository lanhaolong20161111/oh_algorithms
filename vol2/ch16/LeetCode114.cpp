class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;                     //����ֱ�ӷ���
        flatten(root->left);
        flatten(root->right);
        TreeNode *tmp=root->right;                 //��ʱ��ŵ�����B���׽��
        root->right=root->left;
        root->left=NULL;
        TreeNode* p=root;
        while(p->right!=NULL)                   //�ҵ�������A��β���p
            p=p->right;
        p->right=tmp;                           //��������
    }
};

