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
    DNode *front;       //�׽��ָ��
    DNode *mid;         //�н��ָ��
    DNode *rear;        //β���ָ��
    int length;			//���г���
public:
    FrontMiddleBackQueue() {
        front=mid=rear=NULL;
        length=0;
    }
    
    void pushFront(int val) {   //��ӵ����е���ǰ��
        DNode*s=new DNode(val); //�½����val�Ľ��s
        if(length==0) {         //ԭ����Ϊ��
            front=rear=mid=s;  
            length=1;
        }
        else {                  //ԭ���зǿ�
            s->next=front;      //���s���뵽���front��ǰ��
            front->prior=s;
            front=s;
            if(length%2==1)     //ԭ������Ϊ����
                mid=mid->prior;
            length++;
        }
    }
    
    void pushMiddle(int val) {      //��ӵ����е����м�
        DNode*s=new DNode(val); //�½����val�Ľ��s
        if(length==0) {         //ԭ����Ϊ��
            front=rear=mid=s;  
            length=1;
        }
        else if(length==1) {    //ԭ����ֻ��һ�����
            s->next=rear;
            rear->prior=s;
            front=mid=s;
            length++;
        }
        else {                  //�������
            if(length%2==1) {        //ԭ������Ϊ����
                mid->prior->next=s;     //�����s���뵽���mid֮ǰ 
                s->prior=mid->prior;
                s->next=mid;
                mid->prior=s;
            }
            else {                      //ԭ������Ϊż��
                s->next=mid->next;      //�����s���뵽���mid֮�� 
                s->next->prior=s;
                mid->next=s;
                s->prior=mid;
            }
            mid=s;
            length++;
        }
    }
    
    void pushBack(int val) {        //��ӵ�����������
        DNode*s=new DNode(val); //�½����val�Ľ��s
        if(length==0) {         //ԭ����Ϊ��
            front=rear=mid=s;  
            length=1;
        }
        else {                  //ԭ���зǿ�
            s->prior=rear;      //���s���뵽���rear�ĺ���
            rear->next=s;
            rear=s;
            if(length%2==0)     //ԭ������Ϊż��
                mid=mid->next;
            length++;
        }
    }
    
    int popFront() {        //ɾ����ǰ���Ԫ��
        if(length==0) return -1;
        int x=front->val;
        if(length==1) {         //ԭ����ֻ��һ�����
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
    int popMiddle() {    //ɾ���м��Ԫ��
        if(length==0) return -1;
        int x=mid->val;
        if(length==1) {         //ԭ����ֻ��һ�����
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
            if(length%2==0)      //ԭ������Ϊż��
                nmid=mid->next;
            else                //ԭ������Ϊ����
                nmid=mid->prior;
            mid->prior->next=mid->next;
            mid->next->prior=mid->prior;
            delete mid;
            mid=nmid;
            length--;
        }
        return x;
    }
    
    int popBack() {      //ɾ��������Ԫ��
        if(length==0) return -1;
        int x=rear->val;
        if(length==1) {         //ԭ����ֻ��һ�����
            delete rear;
            front=rear=mid=NULL;
            length=0;
        }
        else {
            if(length%2==1)    //ԭ������Ϊ����
                mid=mid->prior;
            DNode*p=rear;
            rear=rear->prior;
            delete p;
            length--;
        }
        return x;
    }
};

