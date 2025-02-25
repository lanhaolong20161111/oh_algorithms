class Solution:
    def minMeetingRooms(self,A:List[List[int]]) -> int:
        n=len(A)
        pqu=[]                          #小根堆
        A.sort(key=lambda x:(x[0]))
        heapq.heappush(pqu,A[0][1])
        for i in range(1,n):
            if A[i][0]>=pqu[0]:         #兼容时出队
                heapq.heappop(pqu)
            heapq.heappush(pqu,A[i][1])
        return len(pqu)
