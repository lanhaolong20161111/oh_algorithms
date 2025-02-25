class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return vector<TreeNode *>{};
        else return generate(1,n);
    }
    vector<TreeNode*> generate(int low,int high) {
        vector<TreeNode *> ans;
        if (low>high) {                                                         //空区间
            ans.push_back(NULL);                                        //构造空树
            return ans;
        }
        for (int i=low;i<=high;i++) {                                       //枚举可行根结点
            vector<TreeNode*> leftbst=generate(low,i-1);    //构造左子树集合
            vector<TreeNode*> rightbst=generate(i+1,high);  //构造右子树集合
            for (TreeNode *l:leftbst) {                                      //拼接
                for (TreeNode *r:rightbst) {
                    TreeNode *b=new TreeNode(i);                        //构造根结点b
                    b->left=l;
                    b->right=r;
                    ans.push_back(b);
                }
            }
        }
        return ans;
    }
};

