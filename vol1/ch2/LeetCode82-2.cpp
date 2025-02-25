class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if(head==NULL || head->next==NULL)
			return head;
		ListNode*h=new ListNode(-1);
		h->next=head;
		ListNode*pre=h,*p=h->next;
		while(p!=NULL) {
			ListNode*q=p->next;     		//q指向结点p的后继结点
			if(q!=NULL && q->val==p->val) {		//结点p是重复结点
				while(q!=NULL && q->val==p->val)	//找到后面第一个非重复结点q
					q=q->next;
				while(p!=q) {
					pre->next=p->next;
					delete p;
				p=pre->next;;
				}
			}
			else {                  					//结点p为非重复的结点
				pre=pre->next;      			//pre,p同步后移
				p=pre->next;
			}
		}
		return h->next;
	}
};


