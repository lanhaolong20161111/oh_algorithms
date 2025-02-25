class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> qu;
        qu.push(root);                              //��������
        TreeNode*last=root;             //��1�����ҽ��
        vector<int> curp;
        while (!qu.empty()) {                           //�Ӳ���ѭ��
            TreeNode*p=qu.front(); qu.pop();            //����һ�����p
            TreeNode*q;
            if (p->left!=NULL) {                      //������ʱ�������
                q=p->left;
                qu.push(q);
            }
            if (p->right!=NULL) {                     //���Һ���ʱ�������
                q=p->right;
                qu.push(q);
            }
            curp.push_back(p->val);                 //��ǰ��Ľ��ֵ��ӵ�curp
            if (p==last) {                          //�ָ�㣺��ǰ������н�㴦�����
                ans.push_back(curp);                //����ǰ����ֵ������ӵ�ans��
                curp.clear();                       //���curp
                last=q;                             //��lastָ����һ������ҽ��
            }
        }
        return ans;
    }
};

