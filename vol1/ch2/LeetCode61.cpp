class Solution {
public:
  	ListNode* rotateRight(ListNode* head, int k) {
       	if(k==0 || head==NULL || head->next==NULL)
           	return head;								//�������
          int n=1;
          ListNode*p=head;
          while(p->next!=NULL) {     			//�������n
          	p=p->next;
            	n++;
         	}                           							//ѭ��������pָ��β���
         p->next=head;               					//����ѭ��������
         k=k%n;
         int m=n-k;
         p=head;                     						//����(p,head)ͬ��ָ��
         head=p->next;
         while(m>1) {               					//p����m-1��
            	m--;
             	p=p->next;	head=p->next;
         }
         p->next=NULL;								//�Ͽ�
         return head;
    }
};

