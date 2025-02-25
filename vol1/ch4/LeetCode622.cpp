class MyCircularQueue {
    int *data;                                      //��Ŷ���Ԫ��
    int front;                                      //��ͷָ��
    int rear;                                       //��βָ��
    int capacity;                                   //����
    int length;                                     //���� 
public:
    MyCircularQueue(int k) {
        data=new int[k];
        capacity=k;
        front=rear=0;
        length=0;
    }
    
    bool enQueue(int value) {      //Ԫ��value����
        if (isFull()) return false;
        rear=(rear+1) % capacity;
        data[rear]=value;
        length++;
        return true;
    }
    
    bool deQueue() {			//����һ��Ԫ��
		if (isEmpty()) return false;
    	front=(front+1) % capacity;
    	length--;
    	return true;
    }
    
    int Front() {				//���ض�ͷԪ��
		if (isEmpty()) return -1;
    	int head=(front+1) % capacity; 
    	return data[head];
    }
    
    int Rear() {				//���ض�βԪ��
		if (isEmpty()) return -1;
    	return data[rear];
    }
    
    bool isEmpty() {        //�ж��Ƿ�Ϊ�ն�
        return length==0; 
    }
    
    bool isFull() {         //�ж��Ƿ����
        return length==capacity;
    }
};

