class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
       	if(head==NULL || head->next==NULL)
           	return head;
        ListNode*h=new ListNode(),*r=h;    	 		//����ͷ���h��βָ��r
        ListNode*p=head;                    					//��p����������
        while(p!=NULL && p->next!=NULL) {   	//����ʣ�������������
        	ListNode*a=p,*b=p->next;
        	p=b->next;
           	r->next=b; b->next=a; r=a;
        }
        if(p!=NULL) {                       					//ʣ��һ���������
           	r->next=p; r=p;
        }
        r->next=NULL;                       					//β����next����Ϊ��
        return h->next;
    }
};

