from collections import deque
class RecentCounter:

    def __init__(self):
        self.qu=deque()

    def ping(self, t: int) -> int:
        self.qu.append(t)
        while self.qu[0]<t-3000:
            self.qu.popleft()
        return len(self.qu)
