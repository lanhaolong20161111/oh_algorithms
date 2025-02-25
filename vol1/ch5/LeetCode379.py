from collections import deque
class PhoneDirectory:
    def __init__(self, maxNumbers: int):
        self.hset=set()
        self.qu=deque()
        for i in range(0,maxNumbers):
            self.qu.append(i)

    def get(self) -> int:
        if self.qu:
            x=self.qu.pop()
            self.hset.add(x)
            return x
        else: return -1

    def check(self, number: int) -> bool:
        if number in self.hset:
            return False
        else:
            return True

    def release(self, number: int) -> None:
        if number in self.hset:
            self.hset.remove(number)
            self.qu.append(number)
