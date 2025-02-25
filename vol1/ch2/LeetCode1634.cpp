class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode*p=poly1;
        PolyNode*q=poly2;
        if(p==NULL) return q;
        if(q==NULL) return p;
        PolyNode*h=new PolyNode();
        PolyNode*r=h,*s;
        while(p!=NULL && q!=NULL) {
            if(p->power>q->power) {
                s=new PolyNode(p->coefficient,p->power);
                r->next=s;
                r=s;
                p=p->next;
            }
            else if(q->power>p->power) {
                s=new PolyNode(q->coefficient,q->power);
                r->next=s;
                r=s;
                q=q->next;
            }
            else {
                int c=p->coefficient+q->coefficient;
                if(c!=0) {
                    s=new PolyNode(c,p->power);
                    r->next=s;
                    r=s;
                }
                p=p->next;
                q=q->next;
            }
        }
        if(q!=NULL) p=q;
        while(p!=NULL) {
            s=new PolyNode(p->coefficient,p->power);
            r->next=s;
            r=s;
            p=p->next;
        }
        return h->next;
    }
};

