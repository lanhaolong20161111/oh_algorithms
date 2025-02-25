class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)
            return root; 
        queue<TreeNode*> qu;
        qu.push(root);                              //��������
        int curl=0;
        while (!qu.empty()) {                           //�Ӳ���ѭ��
            int n=qu.size();
            vector<TreeNode*> curp;
            for(int i=0;i<n;i++) {
                TreeNode*p=qu.front(); qu.pop();           //����һ�����p
                curp.push_back(p);
                if (p->left!=NULL)                      //������ʱ�������
                    qu.push(p->left);
                if (p->right!=NULL)                     //���Һ���ʱ�������
                    qu.push(p->right);
            }
            if(curl%2==1) rev(curp);
            curl++;
        }
        return root;
    }

    void rev(vector<TreeNode*> &a) {			//��תa
        int i=0,j=a.size()-1;
        while(i<j) {
            swap(a[i]->val,a[j]->val);
            i++; j--;
        }
    }
};

