# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
INF=10010
class Solution:
    def mergeKLists(self,lists:List[Optional[ListNode]])->Optional[ListNode]:
        k=len(lists)
        if k==0: return None
        h=ListNode(-1); r=h
        x=[0]*k
        for i in range(0,k):
            if lists[i]!=None: x[i]=lists[i].val
            else: x[i]=INF
        while True:
            mini=self.mink(x,k)
            if mini==-1: break
            r.next=lists[mini]; r=lists[mini]
            lists[mini]=lists[mini].next
            if lists[mini]!=None:
                x[mini]=lists[mini].val
            else:
                x[mini]=INF
        return h.next

    def mink(self,x,k):       #求最小值的段号
        mini=0
        for i in range(1,k):
            if x[i]<x[mini]: mini=i
        if x[mini]==INF: return -1
        else: return mini
