class MyStack {
    queue<int> qu;					//主队列
    queue<int> tmpqu;				//辅助队列
public:
    MyStack() {  }

    void push(int x) {
        while (!qu.empty()) {
            tmpqu.push(qu.front());
            qu.pop();
        }
        qu.push(x);
        while(!tmpqu.empty()) {
            qu.push(tmpqu.front());
            tmpqu.pop();
        }
    }
    int pop() {
        int x=qu.front(); qu.pop();
        return x;
    }
    int top() {
        return qu.front();
    }
    bool empty() {
        return qu.empty();
    }
};

