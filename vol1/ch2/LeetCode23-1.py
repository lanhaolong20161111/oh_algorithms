class Solution:
    def mergeKLists(self,lists:List[Optional[ListNode]])->Optional[ListNode]:
        k=len(lists)
        if k==0:return None
        h=lists[0]
        for i in range(1,k):
            h=self.merge(h,lists[i])
        return h

    def merge(self,list1,list2):
        if list1==None: return list2
        if list2==None: return list1
        h=ListNode(-1); r=h
        p=list1; q=list2
        while p!=None and q!=None:
            if p.val<q.val:
                r.next=p; r=p
                p=p.next
            else:
                r.next=q; r=q
                q=q.next
        if p!=None: r.next=p
        else: r.next=q
        return h.next
