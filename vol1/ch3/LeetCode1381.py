class CustomStack:
    def __init__(self, maxSize: int):
        self.data=[None]*maxSize                         #存放栈元素的动态数组
        self.capacity=maxSize                       #data数组的容量
        self.top=-1                                     #栈顶指针

    def push(self, x: int) -> None:
        if self.top+1<self.capacity:      #没有出现上溢出时
            self.top=self.top+1
            self.data[self.top]=x

    def pop(self) -> int:
        if self.top==-1:
            return -1
        else:
            e=self.data[self.top]
            self.top=self.top-1
            return e

    def increment(self, k: int, val: int) -> None:
        m=k
        if self.top+1<=k:m=self.top+1
        for i in range(0,m):
            self.data[i]+=val