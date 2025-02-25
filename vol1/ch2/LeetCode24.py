class Solution:
    def swapPairs(self, head: Optional[ListNode])->Optional[ListNode]:
        if head==None or head.next==None:
            return head
        h=ListNode(-1); r=h     							#创建头结点h和尾指针r
        p=head                              							#用p遍历单链表
        while p!=None and p.next!=None:   			#至少剩余两个结点的情况
            a,b=p,p.next
            p=b.next
            r.next=b; b.next=a; r=a;
        if p!=None:                       							#剩余一个结点的情况
            r.next=p; r=p
        r.next=None                      							#尾结点的next设置为空
        return h.next
