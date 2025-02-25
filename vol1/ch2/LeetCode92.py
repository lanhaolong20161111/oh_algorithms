# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode],left:int,right:int)->Optional[ListNode]:
        if  head==None or head.next==None:
            return head
        if left==right: return head
        h=ListNode()
        h.next=head                 					#为了方便添加一个头结点
        pre=h; p=pre.next
        j=0;
        while j<left-1 and p!=None:      		#查找left的结点p及其前驱pre
            j=j+1
            pre=p; p=p.next
        while j<right-1 and p!=None:      	#将left+1～right的结点插入到pre之后
            q=p.next
            p.next=q.next                        			#删除结点q 
            q.next=pre.next                  				#将结点q插入到结点pre之后
            pre.next=q
            j=j+1
        return h.next  