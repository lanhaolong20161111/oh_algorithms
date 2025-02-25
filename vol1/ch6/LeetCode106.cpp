class Solution {
public:
    TreeNode* buildTree(vector<int>& in,vector<int>& post) {
        int n=post.size();
        return createbt(post,0,in,0,n);
    }

    TreeNode* createbt(vector<int>&post,int i,vector<int>&in,int j,int n) {
        if (n<=0) return NULL;
        TreeNode*root=new TreeNode(post[n+i-1]);   //���������root
        int p=j;
        while(in[p]!=post[n+i-1]) p++;           //�������������ҵ���pre[i]��λ��p
        int k=p-j;                              //ȷ���������Ľ�����Ϊk
        root->left=createbt(post,i,in,j,k);          //�ݹ鹹��������
        root->right=createbt(post,i+k,in,p+1,n-k-1);     //�ݹ鹹��������
        return root;
    }
};

