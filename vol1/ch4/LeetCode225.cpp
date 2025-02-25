class MyStack {
    queue<int> qu;					//������
    queue<int> tmpqu;				//��������
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

