class MyQueue {
    stack<int> st;
    stack<int> tmpst;
public:
    MyQueue() {}
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(!st.empty()) {    //��stȫ��Ԫ�س�ջ������tmpstջ
            tmpst.push(st.top());
            st.pop();
        }
        int x=tmpst.top(); tmpst.pop();
        while(!tmpst.empty()) {    //��tmpstʣ��Ԫ�س�ջ������stջ
            st.push(tmpst.top());
            tmpst.pop();
        }
        return x;
    }
    
    int peek() {
        while(!st.empty()) {    //��stȫ��Ԫ�س�ջ������tmpstջ
            tmpst.push(st.top());
            st.pop();
        }
        int x=tmpst.top();
        while(!tmpst.empty()) {    //��tmpstʣ��Ԫ�س�ջ������stջ
            st.push(tmpst.top());
            tmpst.pop();
        }
        return x;
    }
    
    bool empty() {
        return st.empty();
    }
};

