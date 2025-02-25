class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string preroot=preorder(root);
        string presubroot=preorder(subRoot);
        int i=preroot.find(presubroot);
        if(i!=-1 && (i==0 || preroot[i-1]=='#' || preroot[i-1]==','))
            return true;
        else
            return false;
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

