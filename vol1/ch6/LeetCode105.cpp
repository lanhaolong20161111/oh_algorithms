class Solution {
public:
    TreeNode* buildTree(vector<int>& pre,vector<int>& in) {
        int n=pre.size();
        return createbt(pre,0,in,0,n);
    }
    TreeNode* createbt(vector<int>& pre,int i,vector<int>& in,int j,int n) {
         if (n<=0) return NULL;
        TreeNode*root=new TreeNode(pre[i]);    //创建根结点root
        int p=j;
        while(in[p]!=pre[i]) p++;           //在中序序列中找等于pre[i]的位置p
        int k=p-j;                              //确定左子树的结点个数为k
        root->left=createbt(pre,i+1,in,j,k);          //递归构造左子树
        root->right=createbt(pre,i+k+1,in,p+1,n-k-1);     //递归构造右子树
        return root;
    }
};

