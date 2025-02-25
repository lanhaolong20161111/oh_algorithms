class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
       	if(head==NULL || head->next==NULL)
           	return head;
        ListNode*h=new ListNode(),*r=h;    	 		//创建头结点h和尾指针r
        ListNode*p=head;                    					//用p遍历单链表
        while(p!=NULL && p->next!=NULL) {   	//至少剩余两个结点的情况
        	ListNode*a=p,*b=p->next;
        	p=b->next;
           	r->next=b; b->next=a; r=a;
        }
        if(p!=NULL) {                       					//剩余一个结点的情况
           	r->next=p; r=p;
        }
        r->next=NULL;                       					//尾结点的next设置为空
        return h->next;
    }
};

