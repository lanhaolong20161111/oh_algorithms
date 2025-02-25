# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head==None or head.next==None:
            return head
        r=head            #尾结点指针
        p=head.next
        while p!=None:
            if p.val!=r.val:    #结点p是非重复结点
                r.next=p; r=p
            p=p.next
        r.next=None               #尾结点的next置为空
        return head