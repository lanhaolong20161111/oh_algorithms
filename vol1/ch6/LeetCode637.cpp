class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> qu;
        qu.push(root);                              //��������
        while (!qu.empty()) {                           //�Ӳ���ѭ��
            int n=qu.size();
            double cursum=0.0;
            for(int i=0;i<n;i++) {
                TreeNode*p=qu.front(); qu.pop();            //����һ�����p
                cursum+=(double)(p->val);			//��ǰ��Ľ��ֵ�ۼƵ�cursum
                if (p->left!=NULL)                      //������ʱ�������
                    qu.push(p->left);
                if (p->right!=NULL)                     //���Һ���ʱ�������
                    qu.push(p->right);
            }
            ans.push_back(cursum/n);
        }
        return ans;
    }
};

