class MinStack {
    vector<int> valst;                          	//valջ 
    vector<int> minst;                          //minջ
public:
    MinStack() {}                    //���캯��

    void push(int val) {                //��ջval
        valst.push_back(val);
        if(minst.empty() || val<=minst.back())
            minst.push_back(val);          //��val��minvalջ
    }
    
    void pop() {                    //��ջ
        int e=valst.back(); valst.pop_back();   //��ջԪ��e
        if(e==minst.back())                 //eΪ��ǰ��СԪ��
            minst.pop_back();       //��e��minջ��ջ
    }
    
    int top() {                     //ȡջ��Ԫ��
        return valst.back();        //����valջ��Ԫ�� 
    }
    
    int getMin() {                      //ȡջ����СԪ��
        return minst.back();        //����minջ��Ԫ�� 
    }
};

