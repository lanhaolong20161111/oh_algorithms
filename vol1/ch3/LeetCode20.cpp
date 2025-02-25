class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        if(n==0) return true;
        stack<char> st;
        for(int i=0;i<n;i++) {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else if(s[i]==')') {
                if(st.empty()) return false;
                if(st.top()!='(') return false;
                st.pop();
            }
            else if(s[i]==']') {
                if(st.empty()) return false;
                if(st.top()!='[') return false;
                st.pop();
            }
            else {                       //s[i]='}'
                if(st.empty()) return false;
                if(st.top()!='{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

