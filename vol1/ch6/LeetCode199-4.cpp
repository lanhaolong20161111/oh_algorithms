class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> qu;
        qu.push(root);                              //��������
        while (!qu.empty()) {                           //�Ӳ���ѭ��
            int n=qu.size();
            for(int i=0;i<n;i++) {
                TreeNode*p=qu.front(); qu.pop();           //����һ�����p
                if(i==n-1) ans.push_back(p->val);       //����ǰ�����ҽ����ӵ�ans��
                if (p->left!=NULL)                      //������ʱ�������
                    qu.push(p->left);
                if (p->right!=NULL)                     //���Һ���ʱ�������
                    qu.push(p->right);
            }
        }
        return ans;
    }
};

