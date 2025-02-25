from collections import deque
class ZigzagIterator:
    def __init__(self, v1: List[int], v2: List[int]):
        self.qu=deque()
        m,n=len(v1),len(v2)
        i,j=0,0
        while i<m and j<n:
            self.qu.append(v1[i]); i+=1
            self.qu.append(v2[j]); j+=1
        while i<m:
            self.qu.append(v1[i]); i+=1
        while j<n:
            self.qu.append(v2[j]); j+=1

    def next(self) -> int:
        return self.qu.popleft()      

    def hasNext(self) -> bool:
        return self.qu
