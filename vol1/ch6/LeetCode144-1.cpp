class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root!=NULL) {
            ans.push_back(root->val);
            vector<int> leftans=preorderTraversal(root->left);
            if(!leftans.empty()) {
                for(int x:leftans)
                    ans.push_back(x);
            }
            vector<int> rightans=preorderTraversal(root->right);
            if(!rightans.empty()) {
                for(int x:rightans)
                    ans.push_back(x);
            }
        }
        return ans;
    }
};


class Solution {
    vector<int> ans;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans;
    }

    void preorder(TreeNode* root) {				//µÝ¹éÏÈÐò±éÀúËã·¨
        if(root!=NULL) {
            ans.push_back(root->val);
            preorder(root->left);
            preorder(root->right);
        }
    }
};

