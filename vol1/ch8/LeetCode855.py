from sortedcontainers import SortedList
class ExamRoom:
    def __init__(self, n: int):
        self.start,self.end=0,n-1
        self.tset=SortedList()

    def seat(self) -> int:
        if len(self.tset)==0:
            self.tset.add(0)
            return 0
        ans,pre=self.start,self.start
        maxdist=self.tset[0]-self.start
        for e in self.tset:
            if maxdist<(e-pre)//2:
                maxdist=(e-pre)//2
                ans=pre+maxdist
            pre=e
        if maxdist<self.end-pre:ans=self.end
        self.tset.add(ans)
        return ans

    def leave(self, p: int) -> None:
        self.tset.remove(p)
