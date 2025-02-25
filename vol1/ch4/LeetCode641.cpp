class MyCircularDeque {
    int *data;                                              //存放队中元素
    int front;                                          //队头指针
    int rear;                                   //队尾指针
    int capacity;                                           //容量
    int length;                                     //长度
public:
    MyCircularDeque(int k) {
    data=(int*)malloc(sizeof(int)*k);
        capacity=k;
        front=rear=0;
        length=0;

    }
    
    bool insertFront(int value) {       //元素value从前端进队
    if(isFull())  return false;
        data[front]=value;
        if (front==0)                              //队头front循环减1
            front=capacity-1;
        else
            front=front-1;
        length++;
        return true;
    }
    
    bool insertLast(int value) {     //元素value从后端进队
    if(isFull()) return false;
        rear=(rear+1) % capacity;         //队尾rear循环加1
        data[rear]=value;
        length++;
        return true; 
    }
    
    bool deleteFront() {            //从前端出队
    if(isEmpty()) return false;
        front=(front+1) % capacity;         //队头front循环加1
        length--;
        return true;
    }
    
    bool deleteLast() {     //从后端出队
    if(isEmpty()) return false;
        if (rear==0)                             //队尾rear循环减1
            rear=capacity-1;
        else
            rear=rear-1;
        length--;
        return true;  
    }
    
    int getFront() {    //返回队头元素
    if(isEmpty()) return -1;
        int head=(front+1) % capacity;
        return data[head];
    }
    
    int getRear() {     //返回队尾元素
    if(isEmpty()) return -1;
        return data[rear];
    }
    
    bool isEmpty() {        //判断是否为空队
    return length==0; 
    }
    
    bool isFull() {     //判断是否队满
    return length==capacity;  
    }
};

