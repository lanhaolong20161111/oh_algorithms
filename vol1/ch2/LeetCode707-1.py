class Node:             #单链表结点类型声明
    def __init__(self,val=0,next=None):
        self.val=val
        self.next=next

class MyLinkedList:
    def __init__(self):
        self.head=Node();                   #单链表头结点
        self.length=0                       #单链表结点个数

    def get(self, i: int) -> int:
        p=self.__geti(i)
        if p==None:return -1
        else: return p.val

    def addAtHead(self, val: int) -> None:
        s=Node(val)                          #创建存放val的结点s
        s.next=self.head.next                             #在首部插入结点s
        self.head.next=s
        self.length=self.length+1

    def addAtTail(self, val: int) -> None:
        s=Node(val)                          #创建存放val的结点s
        r=self.head
        while r.next!=None:                            #查找尾结点r
            r=r.next;
        r.next=s                                              #将结点s链接到末尾
        self.length=self.length+1

    def addAtIndex(self,i:int,val:int) -> None:
        if i<=0:                                           #i<=0时在头部插入
            self.addAtHead(val)
            return
        if i==self.length:                                     #i=长度时在尾部插入
            self.addAtTail(val)
            return
        if i>self.length:                                        #i>链表长度时不插入结点
            return;
        p=self.__geti(i-1)                                  #查找序号为i-1的结点p
        s=Node(val)                          #创建存放val的结点s
        s.next=p.next                                    #在结点p之后插入结点s
        p.next=s
        self.length=self.length+1

    def deleteAtIndex(self,i:int) -> None:
        if i<0 or i>=self.length:                                 #i无效时返回
            return
        pre=self.__geti(i-1)                                #查找序号为i-1的结点pre
        p=pre.next                                  #结点p为删除结点
        pre.next=p.next                                  #删除结点p
        self.length=self.length-1

    def __geti(self,i):  #返回序号i的结点,i无效时返回None
        if i<-1 or i>=self.length: return None          #i错误时返回None
        if i==-1: return self.head                              #i=-1时返回头结点
        if self.length==0:return None                      #空表返回None
        if i==0:return self.head.next                     #i=0时返回首结点
        p=self.head.next                             #首先p指向首结点
        j=0                                                    #j置为0
        while j<i:                                           #指针p移动i个结点
            j=j+1;
            p=p.next;
        return p                                                   #返回p