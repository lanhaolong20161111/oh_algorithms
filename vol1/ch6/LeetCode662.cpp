typedef unsigned long long ULL;
class Solution {
    vector<ULL> first,last;
public:
    int widthOfBinaryTree(TreeNode* root) {
        preorder(root,0,0);      //������Ŵ�0��ʼ
        ULL ans=0;
        for(int i=0;i<first.size();i++) {
            ULL curw=last[i]-first[i]+1;            //��ÿһ��Ŀ��
            ans=max(ans,curw);              //�����Ŀ��
        }
        return (int)ans;
    }
    void preorder(TreeNode* root,int h,ULL no)
        //���������first��last
        {   if (root==NULL) return;
            if (first.size()==h)                //�״η��ʵ�h��Ľ��
                first.push_back(no);            //���׽������ӵ�first��
            if(last.size()==h)                  //�״η��ʵ�h��Ľ��
                last.push_back(no);             //���׽������ӵ�first��
            else                                //���ʵ�h����������
                last[h]=no;                 //���߸���ǰ��,����ŵ�h�����ҽ����
            preorder(root->left,h+1,2*no+1);
            preorder(root->right,h+1,2*no+2);
        }
};

