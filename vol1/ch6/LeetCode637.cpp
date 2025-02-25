class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> qu;
        qu.push(root);                              //根结点进队
        while (!qu.empty()) {                           //队不空循环
            int n=qu.size();
            double cursum=0.0;
            for(int i=0;i<n;i++) {
                TreeNode*p=qu.front(); qu.pop();            //出队一个结点p
                cursum+=(double)(p->val);			//当前层的结点值累计到cursum
                if (p->left!=NULL)                      //有左孩子时将其进队
                    qu.push(p->left);
                if (p->right!=NULL)                     //有右孩子时将其进队
                    qu.push(p->right);
            }
            ans.push_back(cursum/n);
        }
        return ans;
    }
};

