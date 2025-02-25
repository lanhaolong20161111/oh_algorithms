# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self,head:Optional[ListNode],k:int)->Optional[ListNode]:
        h=ListNode()
        h.next=head                         #为了方便添加一个头结点 
        n=0
        pre=h;
        tail=pre.next
        while tail!=None:
            if (n+1) % k==0:                           #找到一个翻转组(pre,tail)
                p=pre.next                 #p指向该翻转组首结点
                for i in range(1,k):                  #将k-1个结点插入到pre结点之后
                    q=p.next                #q指向结点p的后继结点
                    p.next=q.next                    #删除结点q
                    q.next=pre.next                #将结点q插入到pre结点之后
                    pre.next=q
                pre=p                                #前翻转组的尾结点作为后翻转组的首结点
                tail=pre.next
            else:                                        #一个翻转组没有找完
                tail=tail.next                        #tail指针后移
            n=n+1
        return h.next