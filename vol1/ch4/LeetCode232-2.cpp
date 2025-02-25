class MyQueue {
    stack<int> st;
    stack<int> tmpst;
public:
    MyQueue() {}
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if(tmpst.empty()) {
            while(!st.empty()) {    //��stȫ��Ԫ�س�ջ������tmpstջ
                tmpst.push(st.top());
                st.pop();
            }
        }
        int x=tmpst.top(); tmpst.pop();
        return x;
    }
    
    int peek() {
        if(tmpst.empty()) {
            while(!st.empty()) {    //��stȫ��Ԫ�س�ջ������tmpstջ
                tmpst.push(st.top());
                st.pop();
            }
        }
        return tmpst.top();
    }
    
    bool empty() {
        return st.empty() && tmpst.empty();
    }
};

