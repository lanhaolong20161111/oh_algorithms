# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        h=ListNode()        #建立一个头结点h
        p=head
        while p!=None:
            q=p.next
            p.next=h.next                  		#结点p插入到表头
            h.next=p
            p=q
        return h.next