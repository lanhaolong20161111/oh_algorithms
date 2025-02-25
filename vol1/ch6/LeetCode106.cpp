class Solution {
public:
    TreeNode* buildTree(vector<int>& in,vector<int>& post) {
        int n=post.size();
        return createbt(post,0,in,0,n);
    }

    TreeNode* createbt(vector<int>&post,int i,vector<int>&in,int j,int n) {
        if (n<=0) return NULL;
        TreeNode*root=new TreeNode(post[n+i-1]);   //创建根结点root
        int p=j;
        while(in[p]!=post[n+i-1]) p++;           //在中序序列中找等于pre[i]的位置p
        int k=p-j;                              //确定左子树的结点个数为k
        root->left=createbt(post,i,in,j,k);          //递归构造左子树
        root->right=createbt(post,i+k,in,p+1,n-k-1);     //递归构造右子树
        return root;
    }
};

