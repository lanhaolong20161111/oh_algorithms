class Solution {
public:
    ListNode* reverseKGroup(ListNode* head,int k) {
        int n=0;
        ListNode*h=new ListNode(-1);
        h->next=head;                         //为了方便添加一个头结点 
        ListNode*pre=h;
        ListNode*tail=pre->next;
        while (tail!=NULL)
        {   if(++n % k==0)                              //找到一个翻转组(pre,tail)
            {   ListNode*p=pre->next;                 //p指向该翻转组首结点
                for(int i=1;i<k;i++)                    //将k-1个结点插入到pre结点之后
                {   ListNode* q=p->next;                //q指向结点p的后继结点
                    p->next=q->next;                    //删除结点q
                    q->next=pre->next;                //将结点q插入到pre结点之后
                    pre->next =q;
                }
                pre=p;                                //前翻转组的尾结点作为后翻转组的首结点
                tail=pre->next;
            }
            else                                        //一个翻转组没有找完
                tail=tail->next;                        //tail指针后移
    }
        return h->next;
    }
};

