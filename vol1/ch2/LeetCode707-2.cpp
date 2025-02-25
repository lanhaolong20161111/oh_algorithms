struct Node {												//单链表结点类型声明
    int val;
    Node *next;
    Node():next(NULL) {}
    Node(int v):val(v),next(NULL) {}
};
class MyLinkedList {
    Node *rear;       				//单链表尾结点指针
    int length;                     //单链表结点个数
public:
    MyLinkedList() {                //构造函数
        rear=NULL;
        length=0;
    }
    
    int get(int i) {
        Node *p=geti(i);
        if(p==NULL) return -1;
        else return p->val;
    }
    
    void addAtHead(int val) {
        Node *s=new Node(val);  	//创建存放val的结点s
        if(length==0) {             //原链表为空表
            s->next=s;              //构成循环单链表
            rear=s;
        }
        else {                      //原链表为非空表
            s->next=rear->next;     //将结点s插入到结点rear之后
            rear->next=s;
        }
        length++;
    }
    
    void addAtTail(int val) {
        Node *s=new Node(val);  	//创建存放val的结点s
        if(length==0) {             //原链表为空表
            s->next=s;              //构成循环单链表
            rear=s;
        }
        else {                      //原链表为非空表
            s->next=rear->next;     //将结点s插入到结点rear之后
            rear->next=s;
            rear=s;                 //置结点s为尾结点
        }
        length++;
    }
    
    void addAtIndex(int i, int val) {
        if(i<=0) {                      		//i<=0时在头部插入
            addAtHead(val);
            return;
        }
        if(i==length) {                    		//i=长度时在尾部插入
            addAtTail(val);
            return;
        }
        if(i>length)                     	 				//i>链表长度时不插入结点
            return;
        Node *p=geti(i-1);                  				//查找序号为i-1的结点p
        Node *s=new Node(val);                  			//创建存放val的结点s
        s->next=p->next;                        			//在结点p之后插入结点s
        p->next=s;
        length++;
    }
    
    void deleteAtIndex(int i) {
        if(i<0 || i>=length)               						 //i无效时返回
            return;
        if(length==1) {             //原链表只有一个结点
            delete rear;
            rear=NULL;
        }
        else {
            if(i==0) {
                Node*p=rear->next;
                rear->next=p->next;
                delete p;
            }
            else {
                Node *pre=geti(i-1);                   //查找序号为i-1的结点pre
                Node *p=pre->next;                          			//结点p为删除结点
                pre->next=p->next;                          			//删除结点p
                delete p;
                if(i==length-1) {       //删除rear结点
                    rear=pre;           //重置rear
                }
            }
        }
        length--;
    }
private:
    Node *geti(int i) {         //返回序号i的结点,i无效时返回NULL
        if(i<0 || i>=length)
            return NULL;
	    Node *p=rear->next;     //首先p指向首结点
        int j=0;                //j置为0
        while (j<i) {           //指针p移动i个结点
            j++;
            p=p->next;
        }
        return p;               //返回p
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
