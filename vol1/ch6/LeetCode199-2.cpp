struct QNode {                                  //队列元素类
    TreeNode* p;                                //结点p
    int lev;                                    //结点p的层次
    QNode(TreeNode*p,int l):p(p),lev(l) {}  //构造函数
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        queue<QNode> qu;                            //定义一个队列qu
        qu.push(QNode(root,1));                     //根结点(层次为1)进队
        int curl=1;
        TreeNode*pre,*p;
        while (!qu.empty()) {                       //队不空循环
            pre=p;                                  //保存结点p的前一个访问的结点
            QNode e=qu.front(); qu.pop();           //出队一个结点
            p=e.p;
            int lev=e.lev;
            if (p->left!=NULL)                      //有左孩子时将其进队
                qu.push(QNode(p->left,lev+1));
            if (p->right!=NULL)                     //有右孩子时将其进队
                qu.push(QNode(p->right,lev+1));
            if(lev>curl) {                           //分割点：当前结点p为curl+1层的首结点
                ans.push_back(pre->val);             //将curl层的最后一个结点值添加到ans中
                curl++;
            }
        }
        ans.push_back(p->val);      //最下一层最右结点是结点p
        return ans;
    }
};

