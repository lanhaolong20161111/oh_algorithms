from sortedcontainers import SortedList
class MaxStack:
    def __init__(self):
        self.idx=0								#栈中元素个数
        self.valst=dict()						#作为val栈，元素为(序号，元素值)
        self.sl=SortedList()					#有序序列，元素为(元素值,序号)，按元素值递增排列

    def push(self, x: int) -> None:
        self.valst[self.idx]=x
        self.sl.add((x, self.idx))
        self.idx+=1

    def pop(self) -> int:
        i, x = self.valst.popitem()
        self.sl.remove((x, i))
        return x

    def top(self) -> int:
        return next(reversed(self.valst.values()))

    def peekMax(self) -> int:
        return self.sl[-1][0]

    def popMax(self) -> int:
        x, i = self.sl.pop()
        self.valst.pop(i)
        return x