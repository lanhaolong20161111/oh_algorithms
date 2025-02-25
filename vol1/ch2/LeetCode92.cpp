class Solution {
  public:
      ListNode* reverseBetween(ListNode* head, int left, int right) {
         if(head==NULL || head->next==NULL)
             return head;
         if(left==right) return head;
         ListNode*h=new ListNode();
         h->next=head;                           					//为了方便添加一个头结点
         ListNode* pre=h,*p=pre->next,*q;
         int j=0;
         while(j<left-1 && p!=NULL) {           		//查找left的结点p及其前驱pre
             j++;
             pre=p;
             p=p->next;
         }
         while(j<right-1 && p!=NULL) {             	//将left+1～right的结点插入到pre之后
             q=p->next;
             p->next=q->next;                        			//删除结点q 
             q->next=pre->next;                  				//将结点q插入到结点pre之后
             pre->next=q;
             j++;
         }
         return h->next;  
     }
};

