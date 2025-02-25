class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        else if(p==NULL || q==NULL)
            return false;
        else {
            string prep=preorder(p);
            string preq=preorder(q);
            return prep==preq;
        }
    }
    string preorder(TreeNode*root) {
        string pres="";
        if(root==NULL)
            pres='#';
        else {
            pres+=to_string(root->val)+",";        //���ֺ������һ��','
            pres+=preorder(root->left);               //���������������л�����
            pres+=preorder(root->right);              //���������������л�����
        }
        return pres;
    }
};

