class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if(head==NULL || head->next==NULL)
			return head;
		ListNode*h=new ListNode(-1);
		h->next=head;
		ListNode*pre=h,*p=h->next;
		while(p!=NULL) {
			ListNode*q=p->next;     		//qָ����p�ĺ�̽��
			if(q!=NULL && q->val==p->val) {		//���p���ظ����
				while(q!=NULL && q->val==p->val)	//�ҵ������һ�����ظ����q
					q=q->next;
				while(p!=q) {
					pre->next=p->next;
					delete p;
				p=pre->next;;
				}
			}
			else {                  					//���pΪ���ظ��Ľ��
				pre=pre->next;      			//pre,pͬ������
				p=pre->next;
			}
		}
		return h->next;
	}
};


