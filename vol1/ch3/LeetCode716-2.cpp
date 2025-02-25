class MaxStack {
public:
    list<int> valst;        //��������Ϊvalջ
    map<int,vector<list<int>::iterator>> mp;     //ӳ��

    MaxStack() {}       //���캯��

    void push(int x) {           //��ջx
        valst.push_back(x);
        mp[x].push_back(--valst.end());
    }

    int pop() {             //��ջ
        int e=valst.back();
        mp[e].pop_back();
        if(mp[e].empty()) mp.erase(e);		//mp[e]Ϊ��ʱɾ����Ԫ��
        valst.pop_back();
        return e;
    }

    int top() {              //ȡջ��Ԫ��
        return valst.back();
    }

    int peekMax() {          //ȡջ�����Ԫ��
        return mp.rbegin()->first;
    }

    int popMax() {           //��ջ���Ԫ��
        int e=mp.rbegin()->first;
        auto it=mp[e].back();
        mp[e].pop_back();
        if(mp[e].empty()) mp.erase(e);		//mp[e]Ϊ��ʱɾ����Ԫ��
        valst.erase(it);
        return e;
    }
};

