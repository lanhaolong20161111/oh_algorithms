struct QNode {                                  //队列元素类
    TreeNode* p;                                //结点p
    int lev;                                    //结点p的层次
    QNode(TreeNode*p,int l):p(p),lev(l) {}  //构造函数
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<QNode> qu;                            //定义一个队列qu
        qu.push(QNode(root,1));                     //根结点(层次为1)进队
        vector<int> curp;
        int curl=1;
        while (!qu.empty()) {                       //队不空循环
            QNode e=qu.front(); qu.pop();           //出队一个结点
            TreeNode* p=e.p;
            int lev=e.lev;
            if (p->left!=NULL)                      //有左孩子时将其进队
                qu.push(QNode(p->left,lev+1));
            if (p->right!=NULL)                     //有右孩子时将其进队
                qu.push(QNode(p->right,lev+1));
            if(lev==curl)                           //出队结点的层次等于curl
                curp.push_back(p->val);
            else {                                  //首次遇到层次大于curl的出队结点
                ans.push_back(curp);                //将上一层结点值序列添加到ans中
                curp.clear();
                curp.push_back(p->val);
                curl++;
            }
        }
        ans.push_back(curp);//将最下一层结点值序列添加到ans中
        return ans;
    }
};

