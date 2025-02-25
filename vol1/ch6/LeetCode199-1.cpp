class Solution {
    vector<int> ans;                    //��������
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root==NULL) return ans;
        preorder(root,0);
        return ans;     
    }

    void preorder(TreeNode* root, int h)    {
        if (root==NULL) return;
        if (h==ans.size())          //��֤��h��ֻ��ans����ӵ�һ�����ʽ��
            ans.push_back(root->val);
        else                        //��h���������㸲��֮ǰ�Ľ��
            ans[h]=root->val;
        preorder(root->left,h+1);
        preorder(root->right,h+1);
    }
};

