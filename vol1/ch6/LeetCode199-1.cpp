class Solution {
    vector<int> ans;                    //存放求解结果
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root==NULL) return ans;
        preorder(root,0);
        return ans;     
    }

    void preorder(TreeNode* root, int h)    {
        if (root==NULL) return;
        if (h==ans.size())          //保证第h层只向ans中添加第一个访问结点
            ans.push_back(root->val);
        else                        //第h层的其他结点覆盖之前的结点
            ans[h]=root->val;
        preorder(root->left,h+1);
        preorder(root->right,h+1);
    }
};

