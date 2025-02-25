class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head==None or head.next==None:
            return head
        h=ListNode(-1)
        h.next=head
        pre=h; p=h.next
        while p!=None:
            q=p.next     		# q指向结点p的后继结点
            if q!=None and q.val==p.val:		#结点p是重复结点
                while q!=None and q.val==p.val:
                    q=q.next
                while p!=q:        			#删除所有重复的结点
                    pre.next=p.next;p=pre.next
            else:                 	 				#结点p为非重复的结点
                pre=pre.next      				#pre,p同步后移
                p=pre.next
        return h.next
