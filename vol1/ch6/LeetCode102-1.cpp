struct QNode {                                  //����Ԫ����
    TreeNode* p;                                //���p
    int lev;                                    //���p�Ĳ��
    QNode(TreeNode*p,int l):p(p),lev(l) {}  //���캯��
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<QNode> qu;                            //����һ������qu
        qu.push(QNode(root,1));                     //�����(���Ϊ1)����
        vector<int> curp;
        int curl=1;
        while (!qu.empty()) {                       //�Ӳ���ѭ��
            QNode e=qu.front(); qu.pop();           //����һ�����
            TreeNode* p=e.p;
            int lev=e.lev;
            if (p->left!=NULL)                      //������ʱ�������
                qu.push(QNode(p->left,lev+1));
            if (p->right!=NULL)                     //���Һ���ʱ�������
                qu.push(QNode(p->right,lev+1));
            if(lev==curl)                           //���ӽ��Ĳ�ε���curl
                curp.push_back(p->val);
            else {                                  //�״�������δ���curl�ĳ��ӽ��
                ans.push_back(curp);                //����һ����ֵ������ӵ�ans��
                curp.clear();
                curp.push_back(p->val);
                curl++;
            }
        }
        ans.push_back(curp);//������һ����ֵ������ӵ�ans��
        return ans;
    }
};

