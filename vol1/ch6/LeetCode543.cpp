class Solution {
    int ans;                //��Ŵ�
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        depth(root);
        return ans;
    }
    int depth(TreeNode* root) {
        if(root==NULL) return 0;
        int leftd=depth(root->left);
        int rightd=depth(root->right);
        ans=max(ans,leftd+rightd);  //ÿ�����ĵ������������+���������
        return max(leftd,rightd)+1;//���ؽ��r�����
    }
};

