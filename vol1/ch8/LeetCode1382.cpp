class Solution {
    vector<TreeNode*> ins;
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return preorder(0,ins.size()-1);
    }

    void inorder(TreeNode*root) {
        if(root!=NULL) {
            inorder(root->left);
            ins.push_back(root);
            inorder(root->right);
        }
    }

    TreeNode* preorder(int low,int high) {
        if(low>high) return NULL;
        int mid=(low+high)/2;
        TreeNode*root=ins[mid];
        root->left=preorder(low,mid-1);
        root->right=preorder(mid+1,high);
        return root;
    }
};

