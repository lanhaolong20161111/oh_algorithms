class Solution {
public:
    TreeNode* buildTree(vector<int>& pre,vector<int>& in) {
        int n=pre.size();
        return createbt(pre,0,in,0,n);
    }
    TreeNode* createbt(vector<int>& pre,int i,vector<int>& in,int j,int n) {
         if (n<=0) return NULL;
        TreeNode*root=new TreeNode(pre[i]);    //���������root
        int p=j;
        while(in[p]!=pre[i]) p++;           //�������������ҵ���pre[i]��λ��p
        int k=p-j;                              //ȷ���������Ľ�����Ϊk
        root->left=createbt(pre,i+1,in,j,k);          //�ݹ鹹��������
        root->right=createbt(pre,i+k+1,in,p+1,n-k-1);     //�ݹ鹹��������
        return root;
    }
};

