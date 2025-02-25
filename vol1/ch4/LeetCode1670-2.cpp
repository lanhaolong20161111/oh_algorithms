struct DNode {
    int val;
    DNode *prior,*next;
    DNode():prior(NULL),next(NULL) {}
    DNode(int val) {
        this->val=val;
        prior=next=NULL;
    }
};
class FrontMiddleBackQueue {
    DNode *front;       //首结点指针
    DNode *mid;         //中结点指针
    DNode *rear;        //尾结点指针
    int length;			//队列长度
public:
    FrontMiddleBackQueue() {
        front=mid=rear=NULL;
        length=0;
    }
    
    void pushFront(int val) {   //添加到队列的最前面
        DNode*s=new DNode(val); //新建存放val的结点s
        if(length==0) {         //原队列为空
            front=rear=mid=s;  
            length=1;
        }
        else {                  //原队列非空
            s->next=front;      //结点s插入到结点front的前面
            front->prior=s;
            front=s;
            if(length%2==1)     //原结点个数为奇数
                mid=mid->prior;
            length++;
        }
    }
    
    void pushMiddle(int val) {      //添加到队列的正中间
        DNode*s=new DNode(val); //新建存放val的结点s
        if(length==0) {         //原队列为空
            front=rear=mid=s;  
            length=1;
        }
        else if(length==1) {    //原队列只有一个结点
            s->next=rear;
            rear->prior=s;
            front=mid=s;
            length++;
        }
        else {                  //其他情况
            if(length%2==1) {        //原结点个数为奇数
                mid->prior->next=s;     //将结点s插入到结点mid之前 
                s->prior=mid->prior;
                s->next=mid;
                mid->prior=s;
            }
            else {                      //原结点个数为偶数
                s->next=mid->next;      //将结点s插入到结点mid之后 
                s->next->prior=s;
                mid->next=s;
                s->prior=mid;
            }
            mid=s;
            length++;
        }
    }
    
    void pushBack(int val) {        //添加到队里的最后面
        DNode*s=new DNode(val); //新建存放val的结点s
        if(length==0) {         //原队列为空
            front=rear=mid=s;  
            length=1;
        }
        else {                  //原队列非空
            s->prior=rear;      //结点s插入到结点rear的后面
            rear->next=s;
            rear=s;
            if(length%2==0)     //原结点个数为偶数
                mid=mid->next;
            length++;
        }
    }
    
    int popFront() {        //删除最前面的元素
        if(length==0) return -1;
        int x=front->val;
        if(length==1) {         //原队列只有一个结点
            delete front;
            front=rear=mid=NULL;
            length=0;
        }
        else {
            if(length%2==0)
                mid=mid->next;
            DNode*p=front;
            front=front->next;
            delete p;
            length--;
        }
        return x;
    }
    int popMiddle() {    //删除中间的元素
        if(length==0) return -1;
        int x=mid->val;
        if(length==1) {         //原队列只有一个结点
            delete mid;
            front=rear=mid=NULL;
            length=0;
        }
        else if(length==2) {
            delete mid;
            front=mid=rear;
            length=1;
        }
        else {
            DNode*nmid;
            if(length%2==0)      //原结点个数为偶数
                nmid=mid->next;
            else                //原结点个数为奇数
                nmid=mid->prior;
            mid->prior->next=mid->next;
            mid->next->prior=mid->prior;
            delete mid;
            mid=nmid;
            length--;
        }
        return x;
    }
    
    int popBack() {      //删除最后面的元素
        if(length==0) return -1;
        int x=rear->val;
        if(length==1) {         //原队列只有一个结点
            delete rear;
            front=rear=mid=NULL;
            length=0;
        }
        else {
            if(length%2==1)    //原结点个数为奇数
                mid=mid->prior;
            DNode*p=rear;
            rear=rear->prior;
            delete p;
            length--;
        }
        return x;
    }
};

