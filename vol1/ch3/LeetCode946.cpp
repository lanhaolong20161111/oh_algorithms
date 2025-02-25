class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0;
        for(int i=0;i<pushed.size();i++) {                              //��������û�б�����
            st.push(pushed[i]);                             //Ԫ��pushed[i]��ջ
            while(!st.empty() && st.top()==popped[j]) {
                st.pop();                                       //popped[j]��ջ��ƥ��ʱ��ջ
                j++;
            }
        }
        return st.empty();                                  //ջ�շ���true;���򷵻�false
    }
};

