class Solution {
    vector<vector<string>> ans;             //������з���
public:
    vector<vector<string>> partition(string s) {
        vector<string> x;
        dfs(s,x,0);
        return ans;
    }
    void dfs(string s,vector<string>& x,int j) {    //�����㷨
        int n=s.size();
        if(j>=n)
            ans.push_back(x);
        else {
            for(int j1=j;j1<n;j1++) {
                string s1=s.substr(j,j1-j+1);       //���s[j..j1]���Ӵ�s1
                if(isPalindrome(s1)) {
                    x.push_back(s1);
                    dfs(s,x,j1+1);
                    x.pop_back();
                }
            }
        }
    }
    bool isPalindrome(string s) {       //�ж�s�Ƿ�Ϊ����
        int i=0;
        int j=s.size()-1;
        while(i<j) {
            if(s[i]!=s[j])return false;
            i++; j--;
        }
        return true;
    }
};

