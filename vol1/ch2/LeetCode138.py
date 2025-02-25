class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head==None: return None
        h=Node(-1)
        h.next=head               					#为了方便添加一个头结点
        p=h.next
        while p!=None:                       #建立双结点的单链表h
            q=Node(p.val)        	#建立结点p的复制结点q
            q.next=p.next                    		#将结点q插入在结点p之后
            p.next=q
            p=q.next
        p=h.next
        while p!=None:                   			#修改复制结点的random
            if p.random!=None:
                p.next.random=p.random.next
            p=p.next.next
        r=h                     #h为复制单链表的头结点
        p=h.next
        while p!=None:
            q=p.next                			 #q指向复制结点
            p.next=q.next                			#删除结点q
            r.next=q; r=q;
            p=p.next;
        r.next=None
        return h.next