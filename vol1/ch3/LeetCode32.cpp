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
                    st.push(i);							//����ջ��Ϊ���һ��û�б�ƥ��������ŵ��±�
                else										//�ҵ�һ����Ч�����Ӵ�
                    ans=max(ans,i-st.top());		//�䳤��=i-st.top()
            }
        }
        return ans;
    }
};
