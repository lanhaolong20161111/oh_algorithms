class Solution:
    def rotateRight(self,head:Optional[ListNode],k:int)->Optional[ListNode]:
        if k==0 or head==None or head.next==None:
            return head                         			#特殊情况
        p,n=head,1
        while p.next!=None:             				#求结点个数n
            p,n=p.next,n+1
        p.next=head                         				#构成循环单链表
        k=k%n
        m=n-k
        p=head                     						#设置(p,head)同步指针
        head=p.next;
        while m>1:                  						#p后移m-1步
            m=m-1
            p=p.next; head=p.next
        p.next=None             						#断开
        return head
