class Solution {
    vector<string>ans;          //���ȫ�������
    string x;                   //������(һ����Ч���Ŵ�)
public:
    vector<string> generateParenthesis(int n) {
        x="";
        dfs(n,0,0);
        return ans;
    }
    void dfs(int n,int left,int right) {    //�����㷨
        if (x.size()==2*n) {
            ans.push_back(x);       //����Ч���Ŵ���ӵ�ans��
        }
        else {
            if(left<n) {
                x.push_back('(');       //ѡ��'('
                dfs(n,left+1,right);
                x.pop_back();           //����
            }
            if(right<left) {
                x.push_back(')');       //ѡ��')'
                dfs(n,left,right+1);
                x.pop_back();           //���� 
            }
        }
    }
};

