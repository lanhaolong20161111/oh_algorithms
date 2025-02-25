class Solution {
public:
  	ListNode* rotateRight(ListNode* head, int k) {
       	if(k==0 || head==NULL || head->next==NULL)
           	return head;								//特殊情况
          int n=1;
          ListNode*p=head;
          while(p->next!=NULL) {     			//求结点个数n
          	p=p->next;
            	n++;
         	}                           							//循环结束后p指向尾结点
         p->next=head;               					//构成循环单链表
         k=k%n;
         int m=n-k;
         p=head;                     						//设置(p,head)同步指针
         head=p->next;
         while(m>1) {               					//p后移m-1步
            	m--;
             	p=p->next;	head=p->next;
         }
         p->next=NULL;								//断开
         return head;
    }
};

