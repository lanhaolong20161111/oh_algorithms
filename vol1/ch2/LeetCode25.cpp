class Solution {
public:
    ListNode* reverseKGroup(ListNode* head,int k) {
        int n=0;
        ListNode*h=new ListNode(-1);
        h->next=head;                         //Ϊ�˷������һ��ͷ��� 
        ListNode*pre=h;
        ListNode*tail=pre->next;
        while (tail!=NULL)
        {   if(++n % k==0)                              //�ҵ�һ����ת��(pre,tail)
            {   ListNode*p=pre->next;                 //pָ��÷�ת���׽��
                for(int i=1;i<k;i++)                    //��k-1�������뵽pre���֮��
                {   ListNode* q=p->next;                //qָ����p�ĺ�̽��
                    p->next=q->next;                    //ɾ�����q
                    q->next=pre->next;                //�����q���뵽pre���֮��
                    pre->next =q;
                }
                pre=p;                                //ǰ��ת���β�����Ϊ��ת����׽��
                tail=pre->next;
            }
            else                                        //һ����ת��û������
                tail=tail->next;                        //tailָ�����
    }
        return h->next;
    }
};

