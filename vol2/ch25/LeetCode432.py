class DNode :           #双链表结点类型
    def __init__(self):
        self.cnt=0
        self.hset=set()
        self.prior=None
        self.next=None

class AllOne:
    def __init__(self):
        self.hmap={}
        self.head=DNode()       #建立头结点
        self.tail=DNode()       #建立尾结点
        self.head.next=self.tail
        self.tail.prior=self.head

    def insprenode(self,p,s):  #将结点s插入在结点p之前
        p.prior.next=s
        s.prior=p.prior
        s.next=p
        p.prior=s

    def inc(self, key: str) -> None:
        if key not in self.hmap:       #key不在数据结构中
            if self.tail.prior==self.head or self.tail.prior.cnt>1:   #链表空或尾结点cnt>1
                s=DNode();    #新建次数为1的结点
                s.cnt=1
                s.hset.add(key)
                self.insprenode(self.tail,s)       #将结点s插入在结点tail之前
                self.hmap[key]=s                #设置hmap[key]
            elif self.tail.prior.cnt==1:     #链表不空且尾结点cnt=1
                p=self.tail.prior            #p指向尾结点
                p.hset.add(key)            #在尾结点中插入key
                self.hmap[key]=p                     #重置hmap[key]
        else:                          #key在数据结构中
            p=self.hmap.get(key)          #找到在链表中的结点p
            del self.hmap[key]            #从hmap中删除key
            p.hset.remove(key)         #从结点p的字符串列表中删除key
            pre=p.prior         
            if pre==self.head or pre.cnt>p.cnt+1:    #到头了或前面结点不适合插入
                s=DNode()            #新建结点s
                s.cnt=p.cnt+1
                s.hset.add(key)
                self.insprenode(p,s)                #将结点s插入在结点p之前
                self.hmap[key]=s                    #重置hmap[key]           
            elif pre!=self.head and pre.cnt==p.cnt+1:  #没到头且前面结点适合插入
                pre.hset.add(key)          #在结点pre中插入key
                self.hmap[key]=pre
            if len(p.hset)==0:     #结点p为空时删除
                self.delnode(p)             #从链表中删除结点p

    def delnode(self,p):     #在双链表中删除结点p
        p.next.prior=p.prior
        p.prior.next=p.next

    def inspostnode(self,p,s):  #将结点s插入在结点p之后
        p.next.prior=s
        s.next=p.next
        p.next=s
        s.prior=p

    def dec(self, key: str) -> None:
        p=self.hmap.get(key)          #找到key的结点p
        del self.hmap[key]            #从hmap中删除key
        p.hset.remove(key)         #从结点p的字符串列表中删除key
        post=p.next
        if p.cnt==1:                 #原次数为1的特殊情况
            if len(p.hset)==0:     #结点p为空时删除
                self.delnode(p)             #从链表中删除结点p
        else:
            if post==self.tail or post.cnt<p.cnt-1:    #到尾了或后面结点不适合插入
                s=DNode()            #新建结点s
                s.cnt=p.cnt-1
                s.hset.add(key)
                self.inspostnode(p,s)               #将结点s插入在结点p之后
                self.hmap[key]=s                    #重置hmap[key]           
            elif post!=self.tail and post.cnt==p.cnt-1:  #没到头且前面结点适合插入
                post.hset.add(key)          #在结点post中插入key
                self.hmap[key]=post
            if len(p.hset)==0:     #结点p为空时删除
                self.delnode(p)             #从链表中删除结点p

    def getMaxKey(self) -> str:
        if len(self.hmap)==0:
            return ""
        else:
            x=self.head.next.hset.pop()     #从首结点的hset中删除串x
            self.head.next.hset.add(x)      #再添加x即恢复
            return x                        #返回x
            #或return list(self.head.next.hset)[0] ：速度巨慢

    def getMinKey(self) -> str:
        if len(self.hmap)==0:
            return ""
        else:
            x=self.tail.prior.hset.pop()       #从首结点的hset中删除串x
            self.tail.prior.hset.add(x)         #再添加x即恢复
            return x                            #返回x
            #或return list(self.tail.prior.hset)[0]：速度巨慢
