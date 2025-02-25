class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pres) {
        vector<int> ins=pres;
        sort(ins.begin(),ins.end());
        return createbt(pres,0,ins,0,pres.size());
    }
    
    TreeNode* createbt(vector<int>& pres,int i,vector<int>& ins,int j,int n) {
         if (n<=0) return NULL;
        TreeNode*root=new TreeNode(pres[i]);    //创建根结点root
        int p=j;
        while(ins[p]!=pres[i]) p++;           //在中序序列中找等于pres[i]的位置p
        int k=p-j;                              //确定左子树的结点个数为k
        root->left=createbt(pres,i+1,ins,j,k);          //递归构造左子树
        root->right=createbt(pres,i+k+1,ins,p+1,n-k-1);     //递归构造右子树
        return root;
    }
};

