class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int ans=0;
        queue<TreeNode*> qu;
        qu.push(root);                              //��������
        while (!qu.empty()) {                           //�Ӳ���ѭ��
            int n=qu.size();
            vector<int> curp;
            for(int i=0;i<n;i++) {
                TreeNode*p=qu.front(); qu.pop();           //����һ�����p
                curp.push_back(p->val);
                if (p->left!=NULL)                      //������ʱ�������
                    qu.push(p->left);
                if (p->right!=NULL)                     //���Һ���ʱ�������
                    qu.push(p->right);
            }
            ans+=minswaps(curp);
        }
        return ans;
    }

    int minswaps(vector<int> &a) {				//��a��Ϊ��������ٽ�������
        vector<int> b = a;
        sort(b.begin(), b.end());
        unordered_map<int, int> hmap;          //��¼�ź����Ԫ��λ��
        for (int i=0;i<b.size();i++) hmap[b[i]]=i;
        int cnt=0;
        for (int i=0;i<a.size();i++) {
            while (a[i]!=b[i]) {            				//ע�����������Ҫ��ν���
                swap(a[i], a[hmap[a[i]]]);
                cnt++;
            }
        }
        return cnt;
    }
};

