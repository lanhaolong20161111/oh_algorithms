class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next is None: return head  #只有一个结点
        p=self.removeNodes(head.next)    # 返回的链表头一定是最大的
        if head.val<p.val:
            return p          #删除 head结点
        else:
            head.next=p                             #保留 head结点
            return head
