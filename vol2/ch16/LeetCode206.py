class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head;    #递归出口
        p=self.reverseList(head.next)   #反转子链表
        head.next.next=head
        head.next=None
        return p
