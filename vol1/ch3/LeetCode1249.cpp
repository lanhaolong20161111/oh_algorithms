class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for (int i=0;i<s.size();i++) {
            char ch=s[i];
            if (ch=='(')
                st.push(i);
            else if (ch==')') {
                if (!st.empty() && s[st.top()]=='(')
                    st.pop();
                else
                    st.push(i);
            }
        }
        while (!st.empty()) {
            int i=st.top(); st.pop();
            s.erase(s.begin()+i);
        }
        return s;
    }
};

