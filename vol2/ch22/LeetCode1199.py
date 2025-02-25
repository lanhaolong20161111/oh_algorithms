class Solution:
    def minBuildTime(self, blocks: List[int], split: int) -> int:
        pqu=[]  #小根堆
        n=len(blocks)
        if n==1:return blocks[0]
        for i in range(0,n):
            heapq.heappush(pqu,blocks[i])
        while len(pqu)>1:
            x=heapq.heappop(pqu)
            y=heapq.heappop(pqu)
            heapq.heappush(pqu,split+max(x,y))
        return pqu[-1]
