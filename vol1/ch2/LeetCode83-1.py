# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head==None or head.next==None:
            return head;
        pre=head
        p=pre.next
        while p!=None:
            if p.val==pre.val:
                pre.next=p.next     #删除结点p
                p=pre.next;
            else:
                pre=pre.next      #pre,p同步后移
                p=pre.next
        return head
