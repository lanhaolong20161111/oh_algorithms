import heapq
class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        frontpq,backpq=[],[]
        i,j=0,len(costs)-1
        ans=0
        for c in range(0,k):    #循环k轮
            while len(frontpq)<candidates and i<=j:
                heapq.heappush(frontpq,costs[i])   #从前面选candidates个工人
                i+=1
            while len(backpq)<candidates and i<=j:
                heapq.heappush(backpq,costs[j])    #从后面选candidates个工人
                j-=1
            frontc=frontpq[0] if len(frontpq)>0 else 100005
            backc=backpq[0] if len(backpq)>0 else 100005
            if frontc<=backc:
                ans+=frontc                #雇佣代价为frontc的工人
                heapq.heappop(frontpq)
            else:
                ans+=backc                 #雇佣代价为backc的工人
                heapq.heappop(backpq)
        return ans
