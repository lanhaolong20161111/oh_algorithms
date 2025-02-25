class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0;
        for(int i=0;i<pushed.size();i++) {                              //输入序列没有遍历完
            st.push(pushed[i]);                             //元素pushed[i]进栈
            while(!st.empty() && st.top()==popped[j]) {
                st.pop();                                       //popped[j]与栈顶匹配时出栈
                j++;
            }
        }
        return st.empty();                                  //栈空返回true;否则返回false
    }
};

