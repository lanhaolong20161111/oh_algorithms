import heapq
class MedianFinder:
    def __init__(self):
        self.minpq=[]                              #定义一个小根堆
        self.maxpq=[]                            #定义一个大根堆

    def addNum(self, num: int) -> None:
        if len(self.minpq)==0:                                   #若小根堆空
            heapq.heappush(self.minpq,num)
            return;
        if num>self.minpq[0]:                                 #若x大于小根堆堆顶元素
            heapq.heappush(self.minpq,num)                  #将x插入到小根堆中
        else:
            heapq.heappush(self.maxpq,-num)                     #否则将x插入到大根堆中
        if len(self.minpq)<len(self.maxpq):                     #若小根堆元素个数较少
            heapq.heappush(self.minpq,-self.maxpq[0]) #取出大根堆堆顶元素插入到小根堆中
            heapq.heappop(self.maxpq)
        if len(self.minpq)-len(self.maxpq)>1:                   #若小根堆比大根堆至少多2个元素
            heapq.heappush(self.maxpq,-self.minpq[0])        #取出小根堆的堆顶元素插入到大根堆中
            heapq.heappop(self.minpq)

    def findMedian(self) -> float:
        if len(self.minpq)==len(self.maxpq):
            return (self.minpq[0]-self.maxpq[0])/2.0
        else:
            return self.minpq[0]
