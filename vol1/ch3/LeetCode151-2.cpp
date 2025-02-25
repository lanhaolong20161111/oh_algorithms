class MinStack {
    vector<int> valst;                          	//val栈 
    vector<int> minst;                          //min栈
public:
    MinStack() {}                    //构造函数

    void push(int val) {                //进栈val
        valst.push_back(val);
        if(minst.empty() || val<=minst.back())
            minst.push_back(val);          //将val进minval栈
    }
    
    void pop() {                    //出栈
        int e=valst.back(); valst.pop_back();   //出栈元素e
        if(e==minst.back())                 //e为当前最小元素
            minst.pop_back();       //将e从min栈出栈
    }
    
    int top() {                     //取栈顶元素
        return valst.back();        //返回val栈顶元素 
    }
    
    int getMin() {                      //取栈中最小元素
        return minst.back();        //返回min栈顶元素 
    }
};

