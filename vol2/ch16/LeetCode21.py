class Solution:
    def mergeTwoLists(self,list1:Optional[ListNode],list2:Optional[ListNode])->Optional[ListNode]:
        return self.merge(list1,list2)
    def merge(self,a,b):
        if not a:return b
        if not b:return a
        if a.val<b.val:
            a.next=self.merge(a.next,b)
            return a
        else:
            b.next=self.merge(a,b.next)
            return b
