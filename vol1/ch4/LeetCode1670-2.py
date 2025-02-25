class DNode:
    def __init__(self,val=0,prior=None,next=None):
        self.val=val
        self.prior=prior
        self.next=next

class FrontMiddleBackQueue:

    def __init__(self):
        self.front=None       #首结点指针
        self.mid=None         #中结点指针
        self.rear=None        #尾结点指针
        self.length=0           #队列长度

    def pushFront(self, val: int)->None:   #添加到队列的最前面
        s=DNode(val)            #新建存放val的结点s
        if self.length==0:         #原队列为空
            self.front=self.rear=self.mid=s
            self.length=1
        else:                  #原队列非空
            s.next=self.front      #结点s插入到结点self.front的前面
            self.front.prior=s
            self.front=s
            if self.length%2==1:     #原结点个数为奇数
                self.mid=self.mid.prior
            self.length+=1

    def pushMiddle(self, val: int)->None:  #添加到队列的正中间
        s=DNode(val)            #新建存放val的结点s
        if self.length==0:         #原队列为空
            self.front=self.rear=self.mid=s  
            self.length=1
        elif self.length==1:    #原队列只有一个结点
            s.next=self.rear
            self.rear.prior=s
            self.front=self.mid=s
            self.length+=1
        else:                  #其他情况
            if self.length%2==1:       #原结点个数为奇数
                self.mid.prior.next=s     #将结点s插入到结点self.mid之前 
                s.prior=self.mid.prior
                s.next=self.mid
                self.mid.prior=s
            else:                      #原结点个数为偶数
                s.next=self.mid.next      #将结点s插入到结点self.mid之后 
                s.next.prior=s
                self.mid.next=s
                s.prior=self.mid
            self.mid=s
            self.length+=1

    def pushBack(self, val: int)->None:     #添加到队里的最后面
        s=DNode(val)            #新建存放val的结点s
        if self.length==0:        #原队列为空
            self.front=self.rear=self.mid=s  
            self.length=1
        else:                  #原队列非空
            s.prior=self.rear      #结点s插入到结点self.rear的后面
            self.rear.next=s
            self.rear=s
            if self.length%2==0:    #原结点个数为偶数
                self.mid=self.mid.next
            self.length+=1

    def popFront(self)->int:      #删除最前面的元素
        if self.length==0:return -1
        x=self.front.val
        if self.length==1:         #原队列只有一个结点
            self.front=self.rear=self.mid=None
            self.length=0
        else:
            if self.length%2==0:
                self.mid=self.mid.next
            self.front=self.front.next
            self.length-=1
        return x

    def popMiddle(self)->int:     #删除中间的元素
        if self.length==0:return -1
        x=self.mid.val
        if self.length==1:         #原队列只有一个结点
            self.front=self.rear=self.mid=None
            self.length=0
        elif self.length==2:
            self.front=self.mid=self.rear
            self.length=1
        else:
            nmid=None;
            if self.length%2==0:      #原结点个数为偶数
                nmid=self.mid.next
            else:                #原结点个数为奇数
                nmid=self.mid.prior
            self.mid.prior.next=self.mid.next
            self.mid.next.prior=self.mid.prior
            self.mid=nmid
            self.length-=1
        return x

    def popBack(self)->int:       #删除最后面的元素
        if self.length==0:return -1
        x=self.rear.val
        if self.length==1:        #原队列只有一个结点
            self.front=self.rear=self.mid=None
            self.length=0
        else:
            if self.length%2==1:  #原结点个数为奇数
                self.mid=self.mid.prior
            self.rear=self.rear.prior
            self.length-=1
        return x