import heapq
class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.minpq=[]           #小根堆
        self.K=k
        n=len(nums)
        if n<k:
            for i in range(0,n):
                heapq.heappush(self.minpq,nums[i])
        else:
            for i in range(0,self.K):
                heapq.heappush(self.minpq,nums[i])
            for i in range(self.K,n):
                if self.minpq[0]<nums[i]:
                    heapq.heappop(self.minpq)
                    heapq.heappush(self.minpq,nums[i])

    def add(self, val: int) -> int:
        if len(self.minpq)==self.K-1:
            heapq.heappush(self.minpq,val)
        else:
            if self.minpq[0]<val:
                heapq.heappop(self.minpq)
                heapq.heappush(self.minpq,val)
        return self.minpq[0]
