class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        if(root->left==NULL && root->right==NULL)
            return NULL;            //ֻ��һ���������
        queue<TreeNode*> qu;
        qu.push(root);                              //��������
        while (!qu.empty()) {                           //�Ӳ���ѭ��
            int n=qu.size();
            for(int i=0;i<n;i++) {
                TreeNode*p=qu.front(); qu.pop();           //����һ�����p
                if(p==u) {
                    if(i==n-1) return NULL;
                    else return qu.front();
                }
                else {
                    if (p->left!=NULL)                      //������ʱ�������
                        qu.push(p->left);
                    if (p->right!=NULL)                     //���Һ���ʱ�������
                        qu.push(p->right);
                }
            }
        }
        return NULL;
    }
};

