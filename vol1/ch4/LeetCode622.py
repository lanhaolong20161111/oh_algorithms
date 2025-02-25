class MyCircularQueue:
    def __init__(self, k: int):
        self.data=[None]*k      #存放队中元素
        self.front=0            #队头指针
        self.rear=0;            #队尾指针
        self.capacity=k         #容量
        self.length=0;               #长度 

    def enQueue(self, value: int) -> bool:  #元素value进队 
        if self.isFull(): return False
        self.rear=(self.rear+1) % self.capacity
        self.data[self.rear]=value
        self.length+=1
        return True

    def deQueue(self) -> bool:      #出队一个元素
        if self.isEmpty(): return False
        self.front=(self.front+1) % self.capacity;
        self.length-=1
        return True

    def Front(self) -> int:         #返回队头元素
        if self.isEmpty(): return -1
        head=(self.front+1) % self.capacity 
        return self.data[head]

    def Rear(self) -> int:      #返回队尾元素
        if self.isEmpty(): return -1
        return self.data[self.rear]

    def isEmpty(self) -> bool:       #判断是否为空队
        return self.length==0 

    def isFull(self) -> bool:   #判断是否队满
        return self.length==self.capacity
