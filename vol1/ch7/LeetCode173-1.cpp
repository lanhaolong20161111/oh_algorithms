class BSTIterator {
private:
    int curp=-1;
    vector<int> nums;
    void inOrder(TreeNode* root) {
        if (root!=NULL) {
                inOrder(root->left);
                nums.push_back(root->val);
                inOrder(root->right);
        }
    }
public:
    BSTIterator(TreeNode* root) {
        inOrder(root);
    }

    int next() {
        return nums[++curp];
    }
    
    bool hasNext() {
        return curp!=nums.size()-1;
    }
};

