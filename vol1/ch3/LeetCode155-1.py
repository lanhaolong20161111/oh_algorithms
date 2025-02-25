class SNode:            #链栈结点类型
    def __init__(self,val=0,next=None):
        self.val=val            #栈元素
        self.minval=0;          #当前结点为栈顶时栈中最小元素
        self.next=next

class MinStack:
    def __init__(self):								#构造函数
        self.h=SNode()

    def push(self, val: int) -> None:				#进栈val
        p=SNode(val)
        if self.h.next==None or val<=self.h.next.minval:
            p.minval=val                          #栈空或者x小于等于当前栈顶元素的情况
        else:                                            #其他情况
            p.minval=self.h.next.minval
        p.next=self.h.next                            #将结点p插入到表头
        self.h.next=p;

    def pop(self) -> None:						#出栈
        p=self.h.next                       #p指向首结点 
        self.h.next=p.next                   #删除结点p 

    def top(self) -> int:						#取栈顶元素
        return self.h.next.val                            #返回首结点值 

    def getMin(self) -> int:						#取栈中最小元素
        return self.h.next.minval;                 #返回栈顶结点的minval
