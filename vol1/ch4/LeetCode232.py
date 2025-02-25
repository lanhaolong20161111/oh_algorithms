from collections import deque
class MyQueue:
    def __init__(self):
        self.st=deque()
        self.tmpst=deque()

    def push(self, x:int) -> None:
        self.st.append(x)

    def pop(self) -> int:
        if len(self.tmpst)==0:
            while len(self.st)>0:       #将st全部元素出栈并进入tmpst栈
                self.tmpst.append(self.st.pop())
        return self.tmpst.pop()

    def peek(self) -> int:
        if len(self.tmpst)==0:
            while len(self.st)>0:       			#将st全部元素出栈并进入tmpst栈
                self.tmpst.append(self.st.pop())
        return self.tmpst[-1]

    def empty(self) -> bool:
        return not self.st and not self.tmpst
