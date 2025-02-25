struct Node {
    int val;
    Node *next;
    Node():next(NULL) {}
    Node(int v):val(v),next(NULL) {}
};
class MyLinkedList {
    Node *h;                        //������ͷ���
    int length;                      //�����������
public:
    MyLinkedList() {                //���캯��
        h=new Node();
        length=0;
    }
    
    int get(int index) {        //��ȡ�����е�index������ֵ
        Node *p=geti(index);
        if(p==NULL)
            return -1;
        else
            return p->val;
    }
    
    void addAtHead(int val) {
        Node *s=new Node(val);      //�������val�Ľ��s
        s->next=h->next;            //���ײ�������s
        h->next=s;
        length++;
    }
    
    void addAtTail(int val) {
        Node *s=new Node(val);      //�������val�Ľ��s
        Node *r=h;
        while(r->next!=NULL)        //����β���r
            r=r->next;
        r->next=s;                  //�����s���ӵ�ĩβ
        length++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<=0) {                              //i<=0ʱ��ͷ������
            addAtHead(val);
            return;
        }
        if(index==length)                                //index=����ʱ��β������
        {   addAtTail(val);
            return;
        }
        if(index>length)                                 //index>������ʱ��������
            return;
        Node *p=geti(index-1);                  //�������Ϊindex-1�Ľ��p
        Node *s=new Node(val);                  //�������val�Ľ��s
        s->next=p->next;                        //�ڽ��p֮�������s
        p->next=s;
        length++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=length)                        //i��Чʱ����
            return;
        printf("length=%d,h->next=%d\n",length,h->next->val);
        Node *pre=geti(index-1);                            //�������Ϊindex-1�Ľ��pre
        printf("pre->val=%d\n",pre->val);
        Node *p=pre->next;
        pre->next=p->next;
        delete p;
        length--;
    }
private:
    Node *geti(int i) {         //�������i�Ľ��,i��Чʱ����NULL
        if(i<-1 || i>=length) return NULL;         //i����ʱ����NULL
        if(i==-1) return h;                         //i=-1ʱ����ͷ���
        if(length==0) return NULL;                  //�ձ���NULL
        if(i==0) return h->next;                    //i=0ʱ�����׽��
	    Node *p=h->next;                            //����pָ���׽��
     	int j=0;                                                    //j��Ϊ0
      	while (j<i) {                                     //ָ��p�ƶ�i�����
                j++;
                p=p->next;
        }
        return p;                                        //����p
    }
};

