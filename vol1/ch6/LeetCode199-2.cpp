struct QNode {                                  //����Ԫ����
    TreeNode* p;                                //���p
    int lev;                                    //���p�Ĳ��
    QNode(TreeNode*p,int l):p(p),lev(l) {}  //���캯��
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        queue<QNode> qu;                            //����һ������qu
        qu.push(QNode(root,1));                     //�����(���Ϊ1)����
        int curl=1;
        TreeNode*pre,*p;
        while (!qu.empty()) {                       //�Ӳ���ѭ��
            pre=p;                                  //������p��ǰһ�����ʵĽ��
            QNode e=qu.front(); qu.pop();           //����һ�����
            p=e.p;
            int lev=e.lev;
            if (p->left!=NULL)                      //������ʱ�������
                qu.push(QNode(p->left,lev+1));
            if (p->right!=NULL)                     //���Һ���ʱ�������
                qu.push(QNode(p->right,lev+1));
            if(lev>curl) {                           //�ָ�㣺��ǰ���pΪcurl+1����׽��
                ans.push_back(pre->val);             //��curl������һ�����ֵ��ӵ�ans��
                curl++;
            }
        }
        ans.push_back(p->val);      //����һ�����ҽ���ǽ��p
        return ans;
    }
};

