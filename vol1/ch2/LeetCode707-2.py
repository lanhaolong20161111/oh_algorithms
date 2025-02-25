class Node:             #循环单链表结点类型声明
    def __init__(self,val=0,next=None):
        self.val=val
        self.next=next

class MyLinkedList:
    def __init__(self):
        self.rear=None;
        self.length=0;

    def get(self, i: int) -> int:
        p=self.__geti(i)
        if p==None:return -1
        else: return p.val

    def addAtHead(self, val: int) -> None:
        s=Node(val)      #创建存放val的结点s
        if self.length==0:            #原链表为空表
            s.next=s              #构成循环单链表
            self.rear=s
        else:                      #原链表为非空表
            s.next=self.rear.next;     #将结点s插入到结点rear之后
            self.rear.next=s
        self.length=self.length+1

    def addAtTail(self, val: int) -> None:
        s=Node(val)                 #创建存放val的结点s
        if self.length==0:             #原链表为空表
            s.next=s              #构成循环单链表
            self.rear=s
        else:                      #原链表为非空表
            s.next=self.rear.next     #将结点s插入到结点rear之后
            self.rear.next=s
            self.rear=s                 #置结点s为尾结点
        self.length=self.length+1

    def addAtIndex(self,i:int,val:int) -> None:
        if i<=0:                              #i<=0时在头部插入
            self.addAtHead(val)
            return
        if i==self.length:                         #i=长度时在尾部插入
            self.addAtTail(val)
            return
        if i>self.length:                                        #i>链表长度时不插入结点
            return
        p=self.__geti(i-1)                                  #查找序号为i-1的结点p
        s=Node(val);                              #创建存放val的结点s
        s.next=p.next                                    #在结点p之后插入结点s
        p.next=s
        self.length=self.length+1

    def deleteAtIndex(self,i:int) -> None:
        if i<0 or i>=self.length:                                     #i无效时返回
            return
        if self.length==1:             #原链表只有一个结点
            self.rear=None
        else:                      #原链表有2个以以上结点
            if i==0:              #删除首结点
                p=self.rear.next
                self.rear.next=p.next
            else:                  #删除非首结点
                pre=self.__geti(i-1)                   #查找序号为i-1的结点pre
                p=pre.next                                      #结点p为删除结点
                pre.next=p.next                                      #删除结点p
                if i==self.length-1:           #若删除rear结点
                    self.rear=pre           #重置rear
        self.length=self.length-1

    def __geti(self,i):  #返回序号i的结点,i无效时返回None
        if i<0 or i>=self.length:
            return None
        p=self.rear.next;     #首先p指向首结点
        j=0                #j置为0
        while j<i:           #指针p移动i个结点
            j=j+1
            p=p.next
        return p               #返回p