class MaxStack {
    vector<int> valst;                          //valջ 
    vector<int> maxst;                          //maxջ
public:
    MaxStack() { }						//���캯��

    void push(int x) {                  //��ջx
        valst.push_back(x);
        if(maxst.empty())
            maxst.push_back(x);          //��x��maxvalջ
        else
            maxst.push_back(max(x,maxst.back()));
    }

    int pop() {                         //��ջ
        maxst.pop_back();
        int e=valst.back(); valst.pop_back();
        return e;
    }

    int top() {                     //ȡջ��Ԫ��
        return valst.back();        //����valջ��Ԫ��
    }

    int peekMax() {                 //ȡջ�����Ԫ��
        return maxst.back();        //����maxջ��Ԫ��
    }

    int popMax() {                  //��ջ���Ԫ��
        int e=maxst.back();        //eΪmaxջ��Ԫ��
        vector<int> tmp;            //��ʱջ
        while(valst.back()!=e) {
            tmp.push_back(valst.back());
            valst.pop_back();
            maxst.pop_back();
        }
        valst.pop_back();			//��valջ�г�ջ���Ԫ��
 		maxst.pop_back();
        while(!tmp.empty()) {
            push(tmp.back());
            tmp.pop_back();
        }
        return e;
    }
};

