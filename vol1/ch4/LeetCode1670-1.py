from collections import deque
class FrontMiddleBackQueue:

    def __init__(self):
        self.dq=deque()

    def pushFront(self, val: int) -> None:   #添加到队列的最前面
        self.dq.appendleft(val);

    def pushMiddle(self, val: int) -> None:  #添加到队列的正中间
        n=len(self.dq)
        if n==0:
            self.dq.appendleft(val)
        else:
            k=n//2
            for i in range(1,n+1):
                if i==k+1:self.dq.append(val)
                tmp=self.dq.popleft()
                self.dq.append(tmp)

    def pushBack(self, val: int) -> None:     #添加到队里的最后面
        self.dq.append(val)

    def popFront(self) -> int:      #删除最前面的元素
        if not self.dq: return -1
        x=self.dq.popleft()
        return x

    def popMiddle(self) -> int:     #删除中间的元素
        if not self.dq: return -1
        n=len(self.dq)
        k=(n+1)//2
        x=0
        for i in range(1,n+1):
            if i==k:x=self.dq.popleft()
            else:
                tmp=self.dq.popleft()
                self.dq.append(tmp)
        return x;

    def popBack(self) -> int:       #删除最后面的元素
        if not self.dq: return -1
        x=self.dq.pop()
        return x
