class Solution {
    vector<int> ans;										//���Ա�����ڴ�ű�������
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

