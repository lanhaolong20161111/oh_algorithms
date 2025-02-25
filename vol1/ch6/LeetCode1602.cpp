class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        if(root->left==NULL && root->right==NULL)
            return NULL;            //只有一个结点的情况
        queue<TreeNode*> qu;
        qu.push(root);                              //根结点进队
        while (!qu.empty()) {                           //队不空循环
            int n=qu.size();
            for(int i=0;i<n;i++) {
                TreeNode*p=qu.front(); qu.pop();           //出队一个结点p
                if(p==u) {
                    if(i==n-1) return NULL;
                    else return qu.front();
                }
                else {
                    if (p->left!=NULL)                      //有左孩子时将其进队
                        qu.push(p->left);
                    if (p->right!=NULL)                     //有右孩子时将其进队
                        qu.push(p->right);
                }
            }
        }
        return NULL;
    }
};

