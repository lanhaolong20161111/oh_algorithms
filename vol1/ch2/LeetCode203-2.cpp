class Solution {
public:
	ListNode* removeElements(ListNode* head,int val) {
		ListNode*h=new ListNode(),*r=h;    		 //创建头结点h
		ListNode*p=head;
		while(p!=NULL) {
			if(p->val!=val) {							//结点p为保留的结点
				r->next=p; r=p;
				p=p->next;
			}
			else p=p->next;							//结点p为被删的结点
		}
		r->next=NULL;
		return h->next;
	}
};

