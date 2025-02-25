class MyCircularDeque:
    def __init__(self, k: int):
        self.data=[None]*k                         #存放队中元素
        self.front=0                                   #队头指针
        self.rear=0                              #队尾指针
        self.capacity=k                             #容量
        self.length=0                               #长度

    def insertFront(self, value: int) -> bool:  #元素value从前端进队
        if self.isFull(): return False
        self.data[self.front]=value
        if self.front==0:                                      #队头front循环减1
            self.front=self.capacity-1
        else:
            self.front=self.front-1
        self.length+=1
        return True

    def insertLast(self, value: int) -> bool:  #元素value从后端进队
        if self.isFull(): return False
        self.rear=(self.rear+1) % self.capacity                  #队尾rear循环加1
        self.data[self.rear]=value
        self.length+=1
        return True; 

    def deleteFront(self) -> bool:  #从前端出队
        if self.isEmpty():return False
        self.front=(self.front+1) % self.capacity     #队头front循环加1
        self.length-=1
        return True

    def deleteLast(self) -> bool:#从后端出队
        if self.isEmpty():return False
        if self.rear==0:                               #队尾rear循环减1
            self.rear=self.capacity-1
        else:
            self.rear=self.rear-1
        self.length-=1
        return True 

    def getFront(self) -> int:      #返回队头元素
        if self.isEmpty(): return -1
        head=(self.front+1) % self.capacity
        return self.data[head]

    def getRear(self) -> int:       #返回队尾元素
        if self.isEmpty():return -1
        return self.data[self.rear]

    def isEmpty(self) -> bool:  #判断是否为空队
        return self.length==0

    def isFull(self) -> bool:#判断是否队满
        return self.length==self.capacity  
