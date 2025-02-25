class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> qu;
        qu.push(root);                              //根结点进队
        while (!qu.empty()) {                           //队不空循环
            int n=qu.size();
            for(int i=0;i<n;i++) {
                TreeNode*p=qu.front(); qu.pop();           //出队一个结点p
                if(i==n-1) ans.push_back(p->val);       //将当前层最右结点添加到ans中
                if (p->left!=NULL)                      //有左孩子时将其进队
                    qu.push(p->left);
                if (p->right!=NULL)                     //有右孩子时将其进队
                    qu.push(p->right);
            }
        }
        return ans;
    }
};

