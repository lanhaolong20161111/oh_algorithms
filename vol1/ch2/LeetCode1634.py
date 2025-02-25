# Definition for polynomial singly-linked list.
# class PolyNode:
#     def __init__(self, x=0, y=0, next=None):
#         self.coefficient = x
#         self.power = y
#         self.next = next

class Solution:
    def addPoly(self, poly1: 'PolyNode', poly2: 'PolyNode') -> 'PolyNode':
        p,q=poly1,poly2
        if p==None: return q
        if q==None: return p
        h=PolyNode(); r=h
        while p!=None and q!=None:
            if p.power>q.power:
                r.next=p; r=p
                p=p.next
            elif q.power>p.power:
                r.next=q; r=q;
                q=q.next
            else:
                c=p.coefficient+q.coefficient
                if c!=0:
                    p.coefficient=c;
                    r.next=p;
                    r=p;
                p,q=p.next,q.next
        if p!=None: r.next=p
        else: r.next=q
        return h.next 
