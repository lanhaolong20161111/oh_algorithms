struct Node {
    int val;
    Node *next;
    Node():next(NULL) {}
    Node(int v):val(v),next(NULL) {}
};
class MyLinkedList {
    Node *h;                        //单链表头结点
    int length;                      //单链表结点个数
public:
    MyLinkedList() {                //构造函数
        h=new Node();
        length=0;
    }
    
    int get(int index) {        //获取链表中第index个结点的值
        Node *p=geti(index);
        if(p==NULL)
            return -1;
        else
            return p->val;
    }
    
    void addAtHead(int val) {
        Node *s=new Node(val);      //创建存放val的结点s
        s->next=h->next;            //在首部插入结点s
        h->next=s;
        length++;
    }
    
    void addAtTail(int val) {
        Node *s=new Node(val);      //创建存放val的结点s
        Node *r=h;
        while(r->next!=NULL)        //查找尾结点r
            r=r->next;
        r->next=s;                  //将结点s链接到末尾
        length++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<=0) {                              //i<=0时在头部插入
            addAtHead(val);
            return;
        }
        if(index==length)                                //index=长度时在尾部插入
        {   addAtTail(val);
            return;
        }
        if(index>length)                                 //index>链表长度时不插入结点
            return;
        Node *p=geti(index-1);                  //查找序号为index-1的结点p
        Node *s=new Node(val);                  //创建存放val的结点s
        s->next=p->next;                        //在结点p之后插入结点s
        p->next=s;
        length++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=length)                        //i无效时返回
            return;
        printf("length=%d,h->next=%d\n",length,h->next->val);
        Node *pre=geti(index-1);                            //查找序号为index-1的结点pre
        printf("pre->val=%d\n",pre->val);
        Node *p=pre->next;
        pre->next=p->next;
        delete p;
        length--;
    }
private:
    Node *geti(int i) {         //返回序号i的结点,i无效时返回NULL
        if(i<-1 || i>=length) return NULL;         //i错误时返回NULL
        if(i==-1) return h;                         //i=-1时返回头结点
        if(length==0) return NULL;                  //空表返回NULL
        if(i==0) return h->next;                    //i=0时返回首结点
	    Node *p=h->next;                            //首先p指向首结点
     	int j=0;                                                    //j置为0
      	while (j<i) {                                     //指针p移动i个结点
                j++;
                p=p->next;
        }
        return p;                                        //返回p
    }
};

