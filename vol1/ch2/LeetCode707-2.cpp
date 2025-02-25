struct Node {												//����������������
    int val;
    Node *next;
    Node():next(NULL) {}
    Node(int v):val(v),next(NULL) {}
};
class MyLinkedList {
    Node *rear;       				//������β���ָ��
    int length;                     //�����������
public:
    MyLinkedList() {                //���캯��
        rear=NULL;
        length=0;
    }
    
    int get(int i) {
        Node *p=geti(i);
        if(p==NULL) return -1;
        else return p->val;
    }
    
    void addAtHead(int val) {
        Node *s=new Node(val);  	//�������val�Ľ��s
        if(length==0) {             //ԭ����Ϊ�ձ�
            s->next=s;              //����ѭ��������
            rear=s;
        }
        else {                      //ԭ����Ϊ�ǿձ�
            s->next=rear->next;     //�����s���뵽���rear֮��
            rear->next=s;
        }
        length++;
    }
    
    void addAtTail(int val) {
        Node *s=new Node(val);  	//�������val�Ľ��s
        if(length==0) {             //ԭ����Ϊ�ձ�
            s->next=s;              //����ѭ��������
            rear=s;
        }
        else {                      //ԭ����Ϊ�ǿձ�
            s->next=rear->next;     //�����s���뵽���rear֮��
            rear->next=s;
            rear=s;                 //�ý��sΪβ���
        }
        length++;
    }
    
    void addAtIndex(int i, int val) {
        if(i<=0) {                      		//i<=0ʱ��ͷ������
            addAtHead(val);
            return;
        }
        if(i==length) {                    		//i=����ʱ��β������
            addAtTail(val);
            return;
        }
        if(i>length)                     	 				//i>������ʱ��������
            return;
        Node *p=geti(i-1);                  				//�������Ϊi-1�Ľ��p
        Node *s=new Node(val);                  			//�������val�Ľ��s
        s->next=p->next;                        			//�ڽ��p֮�������s
        p->next=s;
        length++;
    }
    
    void deleteAtIndex(int i) {
        if(i<0 || i>=length)               						 //i��Чʱ����
            return;
        if(length==1) {             //ԭ����ֻ��һ�����
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
                Node *pre=geti(i-1);                   //�������Ϊi-1�Ľ��pre
                Node *p=pre->next;                          			//���pΪɾ�����
                pre->next=p->next;                          			//ɾ�����p
                delete p;
                if(i==length-1) {       //ɾ��rear���
                    rear=pre;           //����rear
                }
            }
        }
        length--;
    }
private:
    Node *geti(int i) {         //�������i�Ľ��,i��Чʱ����NULL
        if(i<0 || i>=length)
            return NULL;
	    Node *p=rear->next;     //����pָ���׽��
        int j=0;                //j��Ϊ0
        while (j<i) {           //ָ��p�ƶ�i�����
            j++;
            p=p->next;
        }
        return p;               //����p
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
