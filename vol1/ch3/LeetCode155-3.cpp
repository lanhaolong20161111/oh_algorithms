typedef long long LL;
class MinStack {
    stack<LL> st;
    LL minval=-1;
public:
    MinStack() {  }

    void push(LL val) {
        if(!st.empty()) {       //st·Ç¿Õ
            LL d=val-minval;
            st.push(d);
            if(d<0) minval=val;
        }
        else {                  //stÎª¿Õ
            st.push(0);
            minval=val;
        }
    }

    void pop() {
        LL d=st.top(); st.pop();
        if(d<0) minval=minval-d;
    }
    
    int top() {
        if(st.top()<0) return minval;
        else return st.top()+minval;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        else return minval;
    }
};

