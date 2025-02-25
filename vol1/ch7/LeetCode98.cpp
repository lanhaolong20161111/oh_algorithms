class Solution {
    TreeNode*pre;							//表示当前访问结点的前驱结点
public:
    bool isValidBST(TreeNode* root) {
        pre=NULL;								//中序首结点无前驱结点
        return inorder(root);
    }
    bool inorder(TreeNode*root) {       //判断是否为BST
        if (root==NULL)                 //空树是一棵二叉排序树
            return true;
        else {
            if(!inorder(root->left))    //判断左子树
                return false;           //若左子树不是BST时返回false
            if (pre!=NULL && pre->val>=root->val)
                return false;           //若当前结点值逆序返回false
            pre=root;                   //保存当前结点
            return inorder(root->right);   //判断右子树，返回其结果
        }
    }
};

