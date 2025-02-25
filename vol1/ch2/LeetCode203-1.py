# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self,head:Optional[ListNode],val:int)->Optional[ListNode]:
        p=head
        while p!=None and p.val==val:     	#删除开头的所有val结点
            tmp=p.next
            p=tmp                           #循环结束后p指向第一个不等于val的结点
        if p==None:return None
        head=p             						#结点p为结果单链表的首结点
        pre=p                     				#设置双指针pre,p
        p=p.next
        while p!=None:                   	    #用p遍历剩余结点
            if p.val==val:               	 #结点p为被删结点
                pre.next=p.next
                p=pre.next
            else:                          	#结点p不为被删结点
                pre=p                      	#pre,p同步后移
                p=pre.next
        return head