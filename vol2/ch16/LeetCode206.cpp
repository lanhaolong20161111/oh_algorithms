class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;    //递归出口
        ListNode *p=reverseList(head->next);    //反转子链表
        head->next->next=head;
        head->next=NULL;
        return p;
    }
};

