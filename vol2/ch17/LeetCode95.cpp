class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return vector<TreeNode *>{};
        else return generate(1,n);
    }
    vector<TreeNode*> generate(int low,int high) {
        vector<TreeNode *> ans;
        if (low>high) {                                                         //������
            ans.push_back(NULL);                                        //�������
            return ans;
        }
        for (int i=low;i<=high;i++) {                                       //ö�ٿ��и����
            vector<TreeNode*> leftbst=generate(low,i-1);    //��������������
            vector<TreeNode*> rightbst=generate(i+1,high);  //��������������
            for (TreeNode *l:leftbst) {                                      //ƴ��
                for (TreeNode *r:rightbst) {
                    TreeNode *b=new TreeNode(i);                        //��������b
                    b->left=l;
                    b->right=r;
                    ans.push_back(b);
                }
            }
        }
        return ans;
    }
};

