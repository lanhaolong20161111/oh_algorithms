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
            pres+=to_string(root->val)+",";        //数字后面添加一个','
            pres+=preorder(root->left);               //产生左子树的序列化序列
            pres+=preorder(root->right);              //产生右子树的序列化序列
        }
        return pres;
    }
};

