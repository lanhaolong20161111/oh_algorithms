class FrontMiddleBackQueue {
    deque<int> dq;
public:
    FrontMiddleBackQueue() { }
    
    void pushFront(int val) {       //添加到队列的最前面
        dq.push_front(val);
    }
    
    void pushMiddle(int val) {      //添加到队列的正中间
        int n=dq.size();
        if(n==0) {
            dq.push_front(val);
            return;
        }
        int k=n/2;
        for(int i=1;i<=n;i++) {
            if(i==k+1) dq.push_back(val);
            int tmp=dq.front(); dq.pop_front();
            dq.push_back(tmp);
        }
    }
    
    void pushBack(int val) {        //添加到队里的最后面
        dq.push_back(val);
    }
    
    int popFront() {        //删除最前面的元素
        if(dq.empty()) return -1;
        int x=dq.front(); dq.pop_front();
        return x;
    }
    
    int popMiddle() {           //删除中间的元素
        if(dq.empty()) return -1;
        int n=dq.size();
        int k=(n+1)/2;
        int x;
        for(int i=1;i<=n;i++) {
            if(i==k) {
                x=dq.front(); dq.pop_front();
            }
            else {
                int tmp=dq.front(); dq.pop_front();
                dq.push_back(tmp);
            }
        }
        return x;
    }
    
    int popBack() {              //删除最后面的元素
        if(dq.empty()) return -1;
        int x=dq.back(); dq.pop_back();
        return x;
    }
};

