class MyCircularQueue {
    int *data;                                      //存放队中元素
    int front;                                      //队头指针
    int rear;                                       //队尾指针
    int capacity;                                   //容量
    int length;                                     //长度 
public:
    MyCircularQueue(int k) {
        data=new int[k];
        capacity=k;
        front=rear=0;
        length=0;
    }
    
    bool enQueue(int value) {      //元素value进队
        if (isFull()) return false;
        rear=(rear+1) % capacity;
        data[rear]=value;
        length++;
        return true;
    }
    
    bool deQueue() {			//出队一个元素
		if (isEmpty()) return false;
    	front=(front+1) % capacity;
    	length--;
    	return true;
    }
    
    int Front() {				//返回队头元素
		if (isEmpty()) return -1;
    	int head=(front+1) % capacity; 
    	return data[head];
    }
    
    int Rear() {				//返回队尾元素
		if (isEmpty()) return -1;
    	return data[rear];
    }
    
    bool isEmpty() {        //判断是否为空队
        return length==0; 
    }
    
    bool isFull() {         //判断是否队满
        return length==capacity;
    }
};

