# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1:Optional[ListNode],list2: Optional[ListNode])->Optional[ListNode]:
        if list1==None: return list2
        if list2==None: return list1
        h=ListNode(-1); r=h
        p=list1; q=list2
        while p!=None and q!=None:
            if p.val<q.val:
                r.next=p; r=p
                p=p.next
            else:
                r.next=q; r=q
                q=q.next
        if p!=None: r.next=p
        else: r.next=q
        return h.next
