# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self,head:Optional[ListNode],val:int)->Optional[ListNode]:
        h=ListNode()         		#创建头结点h
        r=h 
        p=head
        while p!=None:
            if p.val!=val: 			#结点p为保留的结点
                r.next=p; r=p
                p=p.next
            else: p=p.next;         #结点p为被删的结点
        r.next=None
        return h.next
