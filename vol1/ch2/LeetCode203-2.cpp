class Solution {
public:
	ListNode* removeElements(ListNode* head,int val) {
		ListNode*h=new ListNode(),*r=h;    		 //����ͷ���h
		ListNode*p=head;
		while(p!=NULL) {
			if(p->val!=val) {							//���pΪ�����Ľ��
				r->next=p; r=p;
				p=p->next;
			}
			else p=p->next;							//���pΪ��ɾ�Ľ��
		}
		r->next=NULL;
		return h->next;
	}
};

