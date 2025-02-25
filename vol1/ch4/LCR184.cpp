class Checkout {
    queue<int> qu;             	//普通队列
  	deque<int> dq;  						//单调队列
public:
    Checkout() {}
    
    int get_max() {
        if(qu.empty()) return -1;
       	return (dq.front());
    }
    
    void add(int val) {
      	qu.push(val);
      	while(!dq.empty() && (dq.back())<val)
          	dq.pop_back();
      	dq.push_back(val);
    }
    
    int remove() {
      	if(qu.empty()) return -1;
      	int x=qu.front();
      	if(dq.front()==x)
          	dq.pop_front();
       	qu.pop();
       	return x;
    }
};

