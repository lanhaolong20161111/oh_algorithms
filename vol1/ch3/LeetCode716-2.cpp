class MaxStack {
public:
    list<int> valst;        //用链表作为val栈
    map<int,vector<list<int>::iterator>> mp;     //映射

    MaxStack() {}       //构造函数

    void push(int x) {           //进栈x
        valst.push_back(x);
        mp[x].push_back(--valst.end());
    }

    int pop() {             //出栈
        int e=valst.back();
        mp[e].pop_back();
        if(mp[e].empty()) mp.erase(e);		//mp[e]为空时删除该元素
        valst.pop_back();
        return e;
    }

    int top() {              //取栈顶元素
        return valst.back();
    }

    int peekMax() {          //取栈中最大元素
        return mp.rbegin()->first;
    }

    int popMax() {           //出栈最大元素
        int e=mp.rbegin()->first;
        auto it=mp[e].back();
        mp[e].pop_back();
        if(mp[e].empty()) mp.erase(e);		//mp[e]为空时删除该元素
        valst.erase(it);
        return e;
    }
};

