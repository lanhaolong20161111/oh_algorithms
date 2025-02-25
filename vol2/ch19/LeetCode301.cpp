class Solution {
    vector<string> ans;     //存放答案
public:
    vector<string> removeInvalidParentheses(string s) {
        int left=0,right=0;
        for(int i=0;i<s.size();i++) {
            if (s[i]=='(') left++;      //累计左括号数
            else if (s[i]==')') {
                if (left==0) right++;   //不匹配的右括号数增加1
                else left--;            //不匹配的左括号数减少1
            }
        }
        dfs(s,0,left,right);
        return ans;
    }
    void dfs(string s,int j,int left,int right) {   //回溯算法
        if (left==0 && right==0) {          //找到一个解
            if (valid(s)) ans.push_back(s);
        }
        else {
            for (int j1=j;j1<s.size();j1++) {		//j1从j到n-1循环
                if (j1>j && s[j1]==s[j1-1])    //去重
                    continue;
                if (left>0 && s[j1]=='(')    //尝试去掉一个左括号
                    dfs(s.substr(0,j1)+s.substr(j1+1),j1,left-1,right);
                if (right>0 && s[j1]==')')   //尝试去掉一个右括号
                    dfs(s.substr(0,j1)+s.substr(j1+1),j1,left,right-1);
            }
        }
    }
    bool valid(string&s) {                     //判断s中的括号是否匹配
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

