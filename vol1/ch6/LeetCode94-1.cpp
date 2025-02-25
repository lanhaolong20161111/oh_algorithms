class Solution {
    vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }

    void inorder(TreeNode* root) {					//µÝ¹éÖÐÐò±éÀúËã·¨
        if(root!=NULL) {
            inorder(root->left);
            ans.push_back(root->val);
            inorder(root->right);
        }
    }
};

