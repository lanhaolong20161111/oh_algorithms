class MaxStack {
    vector<int> valst;                          //val栈 
    vector<int> maxst;                          //max栈
public:
    MaxStack() { }						//构造函数

    void push(int x) {                  //进栈x
        valst.push_back(x);
        if(maxst.empty())
            maxst.push_back(x);          //将x进maxval栈
        else
            maxst.push_back(max(x,maxst.back()));
    }

    int pop() {                         //出栈
        maxst.pop_back();
        int e=valst.back(); valst.pop_back();
        return e;
    }

    int top() {                     //取栈顶元素
        return valst.back();        //返回val栈顶元素
    }

    int peekMax() {                 //取栈中最大元素
        return maxst.back();        //返回max栈顶元素
    }

    int popMax() {                  //出栈最大元素
        int e=maxst.back();        //e为max栈顶元素
        vector<int> tmp;            //临时栈
        while(valst.back()!=e) {
            tmp.push_back(valst.back());
            valst.pop_back();
            maxst.pop_back();
        }
        valst.pop_back();			//从val栈中出栈最大元素
 		maxst.pop_back();
        while(!tmp.empty()) {
            push(tmp.back());
            tmp.pop_back();
        }
        return e;
    }
};

