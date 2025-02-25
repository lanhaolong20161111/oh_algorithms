class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        if(n==0) return 0;
        int ans=0;
        stack<int> st;
        st.push(-1);
        for (int i=0;i<n;i++) {
            if (s[i]=='(') {
                st.push(i);
            }
            else {
                st.pop();
                if (st.empty())
                    st.push(i);							//更新栈底为最后一个没有被匹配的右括号的下标
                else										//找到一个有效括号子串
                    ans=max(ans,i-st.top());		//其长度=i-st.top()
            }
        }
        return ans;
    }
};
