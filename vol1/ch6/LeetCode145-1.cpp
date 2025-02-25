class Solution {
    vector<int> ans;										//类成员，用于存放遍历序列
public:
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }

    void postorder(TreeNode* root) {
        if(root!=NULL) {
            postorder(root->left);
            postorder(root->right);
            ans.push_back(root->val);
        }
    }
};

