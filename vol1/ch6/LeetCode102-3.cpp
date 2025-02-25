class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> qu;
        qu.push(root);                              //根结点进队
        while (!qu.empty()) {                           //队不空循环
            int n=qu.size();
            vector<int> curp;							//保存一层的结点值序列
            for(int i=0;i<n;i++) {
                TreeNode*p=qu.front(); qu.pop();            //出队一个结点p
                curp.push_back(p->val);
                if (p->left!=NULL)                      //有左孩子时将其进队
                    qu.push(p->left);
                if (p->right!=NULL)                     //有右孩子时将其进队
                    qu.push(p->right);
            }
            ans.push_back(curp);
        }
        return ans;
    }
};

