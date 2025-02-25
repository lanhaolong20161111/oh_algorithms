struct SNode {                  //��ջ�������
    int val;                    //ջԪ��
    int minval;                 //��ǰ���Ϊջ��ʱջ����СԪ��
    SNode *next;
    SNode():next(NULL) {}
    SNode(int v):val(v),next(NULL) {}
}; 

class MinStack {
    SNode *h;                   //��ջͷ���
public:
    MinStack() {                    //���캯��
        h=new SNode();
    }

    void push(int val) {                //��ջval
        SNode*p=new SNode(val);
        if (h->next==NULL || val<=h->next->minval)
            p->minval=val;                          //ջ�ջ���xС�ڵ��ڵ�ǰջ��Ԫ�ص����
        else                                            //�������
            p->minval=h->next->minval;
        p->next=h->next;                            //�����p���뵽��ͷ
        h->next=p;
    }

    void pop() {                    //��ջ
        SNode *p=h->next;                       //pָ���׽��
        h->next=p->next;                                //ɾ�����p 
        delete p;
    }

    int top() {                     //ȡջ��Ԫ��
        return h->next->val;                            //�����׽���valֵ 
    }
    
    int getMin() {                      //ȡջ����СԪ��
        return h->next->minval;                 //�����׽���minval
    }
};

