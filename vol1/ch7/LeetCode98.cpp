class Solution {
    TreeNode*pre;							//��ʾ��ǰ���ʽ���ǰ�����
public:
    bool isValidBST(TreeNode* root) {
        pre=NULL;								//�����׽����ǰ�����
        return inorder(root);
    }
    bool inorder(TreeNode*root) {       //�ж��Ƿ�ΪBST
        if (root==NULL)                 //������һ�ö���������
            return true;
        else {
            if(!inorder(root->left))    //�ж�������
                return false;           //������������BSTʱ����false
            if (pre!=NULL && pre->val>=root->val)
                return false;           //����ǰ���ֵ���򷵻�false
            pre=root;                   //���浱ǰ���
            return inorder(root->right);   //�ж�����������������
        }
    }
};

