class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> qu;
        qu.push(root);                              //��������
        while (!qu.empty()) {                           //�Ӳ���ѭ��
            int n=qu.size();
            vector<int> curp;							//����һ��Ľ��ֵ����
            for(int i=0;i<n;i++) {
                TreeNode*p=qu.front(); qu.pop();            //����һ�����p
                curp.push_back(p->val);
                if (p->left!=NULL)                      //������ʱ�������
                    qu.push(p->left);
                if (p->right!=NULL)                     //���Һ���ʱ�������
                    qu.push(p->right);
            }
            ans.push_back(curp);
        }
        return ans;
    }
};

