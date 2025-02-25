import heapq

STATIC_EID = 0

class Event:
    def __init__(self, ctime, name) -> None:
        self._ctime = ctime
        global STATIC_EID
        self._eid = STATIC_EID
        STATIC_EID += 1
        print('eid:', self._eid)
        self._name = name

    def __lt__(self, other):
        if self._ctime < other._ctime:
            return True
        elif self._ctime == other._ctime:
            if self._eid < other._eid:
                return True
            else:
                return False
        else:
            return False
    
    def call(self):
        print(self._name)


if __name__ == "__main__":
    pq = []
    heapq.heappush(pq, Event(100, 'a'))
    heapq.heappush(pq, Event(20, 'b'))
    heapq.heappush(pq, Event(100, 'c'))
    heapq.heappush(pq, Event(20, 'd'))

    heapq.heappop(pq).call()
    heapq.heappop(pq).call()
    heapq.heappop(pq).call()
    heapq.heappop(pq).call()
