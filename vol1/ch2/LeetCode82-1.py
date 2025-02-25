# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head==None or head.next==None:
            return head
        cnt=[0]*205
        p=head
        while p!=None:
            cnt[100+p.val]=cnt[100+p.val]+1
            p=p.next
        h=ListNode(-1);
        r=h
        p=head
        while p!=None:
            if cnt[100+p.val]==1: #结点p是非重复的
                r.next=p; r=p
            p=p.next
        r.next=None #尾结点的next置为空
        return h.next
