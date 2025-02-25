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
            pres+=to_string(root->val)+",";        //���ֺ������һ��','
            pres+=preorder(root->left);               //���������������л�����
            pres+=preorder(root->right);              //���������������л�����
        }
        return pres;
    }
};

