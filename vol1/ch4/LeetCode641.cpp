class MyCircularDeque {
    int *data;                                              //��Ŷ���Ԫ��
    int front;                                          //��ͷָ��
    int rear;                                   //��βָ��
    int capacity;                                           //����
    int length;                                     //����
public:
    MyCircularDeque(int k) {
    data=(int*)malloc(sizeof(int)*k);
        capacity=k;
        front=rear=0;
        length=0;

    }
    
    bool insertFront(int value) {       //Ԫ��value��ǰ�˽���
    if(isFull())  return false;
        data[front]=value;
        if (front==0)                              //��ͷfrontѭ����1
            front=capacity-1;
        else
            front=front-1;
        length++;
        return true;
    }
    
    bool insertLast(int value) {     //Ԫ��value�Ӻ�˽���
    if(isFull()) return false;
        rear=(rear+1) % capacity;         //��βrearѭ����1
        data[rear]=value;
        length++;
        return true; 
    }
    
    bool deleteFront() {            //��ǰ�˳���
    if(isEmpty()) return false;
        front=(front+1) % capacity;         //��ͷfrontѭ����1
        length--;
        return true;
    }
    
    bool deleteLast() {     //�Ӻ�˳���
    if(isEmpty()) return false;
        if (rear==0)                             //��βrearѭ����1
            rear=capacity-1;
        else
            rear=rear-1;
        length--;
        return true;  
    }
    
    int getFront() {    //���ض�ͷԪ��
    if(isEmpty()) return -1;
        int head=(front+1) % capacity;
        return data[head];
    }
    
    int getRear() {     //���ض�βԪ��
    if(isEmpty()) return -1;
        return data[rear];
    }
    
    bool isEmpty() {        //�ж��Ƿ�Ϊ�ն�
    return length==0; 
    }
    
    bool isFull() {     //�ж��Ƿ����
    return length==capacity;  
    }
};

