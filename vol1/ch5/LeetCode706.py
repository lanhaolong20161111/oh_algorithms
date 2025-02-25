class SNode:                    #单链表结点类型
    def __init__(self,k,v):
        self.key=k              #键
        self.val=v              #值
        self.next=None      

class MyHashMap:
    def __init__(self):
        self.MAXH=997
        self.ht=[None]*self.MAXH

    def search(self,key):    #查找为key的结点,没有时返回NULL
        d=key%self.MAXH                    #计算哈希函数值
        p=self.ht[d]                    #p指向ht[d]单链表的首结点
        while p!=None and p.key!=key:          #遍历ht[d]单链表
            p=p.next
        return p

    def put(self, key:int,value:int)->None:
        p=self.search(key);
        if p!=None:
            p.val=value
        else:        
            d=key%self.MAXH                                 #计算哈希函数值
            q=SNode(key,value);              #新建结点q存放key
            if self.ht[d]==None:                            #若单链表ht[d]为空
                self.ht[d]=q
            else:                                      #若单链表ht[d]不空
                q.next=self.ht[d]                          #采用头插法插入到ha[adr]的单链表中
                self.ht[d]=q

    def get(self,key:int) -> int:
        p=self.search(key)
        if p!=None:                             #找到为key的结点
            return p.val
        else:                                    #没有找到为key的结点
            return -1

    def remove(self,key:int)->None:
        d=key % self.MAXH                                       #计算哈希函数值
        pre=self.ht[d]                                 #pre指向ht[d]单链表的首结点
        if pre==None: return
        if pre.key==key:                               #结点pre是要删除的结点
            self.ht[d]=pre.next
        else:                                               #查找key结点p
            p=pre.next
            while p!=None and p.key!=key:
                pre,p=p,p.next
            if p!=None:pre.next=p.next
