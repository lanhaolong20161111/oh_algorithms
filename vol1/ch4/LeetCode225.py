from collections import deque
class MyStack:
    def __init__(self):
        self.qu=deque()     #主队列
        self.tmpqu=deque()  #辅助队列

    def push(self, x: int) -> None:
        while self.qu:
            self.tmpqu.append(self.qu.popleft())
        self.qu.append(x)
        while self.tmpqu:
            self.qu.append(self.tmpqu.popleft())

    def pop(self) -> int:
        return self.qu.popleft()

    def top(self) -> int:
        return self.qu[0]

    def empty(self) -> bool:
        return len(self.qu)==0
