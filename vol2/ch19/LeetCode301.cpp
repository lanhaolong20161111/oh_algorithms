class Solution {
    vector<string> ans;     //��Ŵ�
public:
    vector<string> removeInvalidParentheses(string s) {
        int left=0,right=0;
        for(int i=0;i<s.size();i++) {
            if (s[i]=='(') left++;      //�ۼ���������
            else if (s[i]==')') {
                if (left==0) right++;   //��ƥ���������������1
                else left--;            //��ƥ���������������1
            }
        }
        dfs(s,0,left,right);
        return ans;
    }
    void dfs(string s,int j,int left,int right) {   //�����㷨
        if (left==0 && right==0) {          //�ҵ�һ����
            if (valid(s)) ans.push_back(s);
        }
        else {
            for (int j1=j;j1<s.size();j1++) {		//j1��j��n-1ѭ��
                if (j1>j && s[j1]==s[j1-1])    //ȥ��
                    continue;
                if (left>0 && s[j1]=='(')    //����ȥ��һ��������
                    dfs(s.substr(0,j1)+s.substr(j1+1),j1,left-1,right);
                if (right>0 && s[j1]==')')   //����ȥ��һ��������
                    dfs(s.substr(0,j1)+s.substr(j1+1),j1,left,right-1);
            }
        }
    }
    bool valid(string&s) {                     //�ж�s�е������Ƿ�ƥ��
        int cnt=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='(') cnt++;
            else if(s[i]==')') {
                cnt--;
                if (cnt<0) return false;
            }
        }
        return cnt==0;
    }
};

