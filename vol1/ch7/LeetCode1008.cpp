class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pres) {
        vector<int> ins=pres;
        sort(ins.begin(),ins.end());
        return createbt(pres,0,ins,0,pres.size());
    }
    
    TreeNode* createbt(vector<int>& pres,int i,vector<int>& ins,int j,int n) {
         if (n<=0) return NULL;
        TreeNode*root=new TreeNode(pres[i]);    //���������root
        int p=j;
        while(ins[p]!=pres[i]) p++;           //�������������ҵ���pres[i]��λ��p
        int k=p-j;                              //ȷ���������Ľ�����Ϊk
        root->left=createbt(pres,i+1,ins,j,k);          //�ݹ鹹��������
        root->right=createbt(pres,i+k+1,ins,p+1,n-k-1);     //�ݹ鹹��������
        return root;
    }
};

