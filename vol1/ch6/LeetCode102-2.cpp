class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> qu;
        qu.push(root);                              //根结点进队
        TreeNode*last=root;             //第1层最右结点
        vector<int> curp;
        while (!qu.empty()) {                           //队不空循环
            TreeNode*p=qu.front(); qu.pop();            //出队一个结点p
            TreeNode*q;
            if (p->left!=NULL) {                      //有左孩子时将其进队
                q=p->left;
                qu.push(q);
            }
            if (p->right!=NULL) {                     //有右孩子时将其进队
                q=p->right;
                qu.push(q);
            }
            curp.push_back(p->val);                 //当前层的结点值添加到curp
            if (p==last) {                          //分割点：当前层的所有结点处理完毕
                ans.push_back(curp);                //将当前层结点值序列添加到ans中
                curp.clear();                       //清空curp
                last=q;                             //让last指向下一层的最右结点
            }
        }
        return ans;
    }
};

