struct SNode {                  //链栈结点类型
    int val;                    //栈元素
    int minval;                 //当前结点为栈顶时栈中最小元素
    SNode *next;
    SNode():next(NULL) {}
    SNode(int v):val(v),next(NULL) {}
}; 

class MinStack {
    SNode *h;                   //链栈头结点
public:
    MinStack() {                    //构造函数
        h=new SNode();
    }

    void push(int val) {                //进栈val
        SNode*p=new SNode(val);
        if (h->next==NULL || val<=h->next->minval)
            p->minval=val;                          //栈空或者x小于等于当前栈顶元素的情况
        else                                            //其他情况
            p->minval=h->next->minval;
        p->next=h->next;                            //将结点p插入到表头
        h->next=p;
    }

    void pop() {                    //出栈
        SNode *p=h->next;                       //p指向首结点
        h->next=p->next;                                //删除结点p 
        delete p;
    }

    int top() {                     //取栈顶元素
        return h->next->val;                            //返回首结点的val值 
    }
    
    int getMin() {                      //取栈中最小元素
        return h->next->minval;                 //返回首结点的minval
    }
};

