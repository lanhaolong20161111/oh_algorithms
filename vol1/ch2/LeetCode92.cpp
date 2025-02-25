class Solution {
  public:
      ListNode* reverseBetween(ListNode* head, int left, int right) {
         if(head==NULL || head->next==NULL)
             return head;
         if(left==right) return head;
         ListNode*h=new ListNode();
         h->next=head;                           					//Ϊ�˷������һ��ͷ���
         ListNode* pre=h,*p=pre->next,*q;
         int j=0;
         while(j<left-1 && p!=NULL) {           		//����left�Ľ��p����ǰ��pre
             j++;
             pre=p;
             p=p->next;
         }
         while(j<right-1 && p!=NULL) {             	//��left+1��right�Ľ����뵽pre֮��
             q=p->next;
             p->next=q->next;                        			//ɾ�����q 
             q->next=pre->next;                  				//�����q���뵽���pre֮��
             pre->next=q;
             j++;
         }
         return h->next;  
     }
};

