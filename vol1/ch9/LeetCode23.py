import heapq
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        k=len(lists)
        if k==0: return None
        h=ListNode(-1); r=h
        pq=[]
        for i in range(0,k):
            if lists[i]!=None:
                pq.append([lists[i].val,i])
        heapq.heapify(pq)
        while len(pq)>0:
            e=heapq.heappop(pq)
            mini=e[1]
            r.next=lists[mini]; r=lists[mini]
            lists[mini]=lists[mini].next
            if lists[mini]!=None:
                heapq.heappush(pq,[lists[mini].val,mini])
        return h.next
