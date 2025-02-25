class MyQueue {
    stack<int> st;
    stack<int> tmpst;
public:
    MyQueue() {}
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(!st.empty()) {    //将st全部元素出栈并进入tmpst栈
            tmpst.push(st.top());
            st.pop();
        }
        int x=tmpst.top(); tmpst.pop();
        while(!tmpst.empty()) {    //将tmpst剩余元素出栈并进入st栈
            st.push(tmpst.top());
            tmpst.pop();
        }
        return x;
    }
    
    int peek() {
        while(!st.empty()) {    //将st全部元素出栈并进入tmpst栈
            tmpst.push(st.top());
            st.pop();
        }
        int x=tmpst.top();
        while(!tmpst.empty()) {    //将tmpst剩余元素出栈并进入st栈
            st.push(tmpst.top());
            tmpst.pop();
        }
        return x;
    }
    
    bool empty() {
        return st.empty();
    }
};

