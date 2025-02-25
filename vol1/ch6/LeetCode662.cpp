typedef unsigned long long ULL;
class Solution {
    vector<ULL> first,last;
public:
    int widthOfBinaryTree(TreeNode* root) {
        preorder(root,0,0);      //根结点编号从0开始
        ULL ans=0;
        for(int i=0;i<first.size();i++) {
            ULL curw=last[i]-first[i]+1;            //求每一层的宽度
            ans=max(ans,curw);              //求树的宽度
        }
        return (int)ans;
    }
    void preorder(TreeNode* root,int h,ULL no)
        //先序遍历求first和last
        {   if (root==NULL) return;
            if (first.size()==h)                //首次访问第h层的结点
                first.push_back(no);            //将首结点编号添加到first中
            if(last.size()==h)                  //首次访问第h层的结点
                last.push_back(no);             //将首结点编号添加到first中
            else                                //访问第h层的其他结点
                last[h]=no;                 //后者覆盖前者,最后存放第h层最右结点编号
            preorder(root->left,h+1,2*no+1);
            preorder(root->right,h+1,2*no+2);
        }
};

