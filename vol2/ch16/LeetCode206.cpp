class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;    //�ݹ����
        ListNode *p=reverseList(head->next);    //��ת������
        head->next->next=head;
        head->next=NULL;
        return p;
    }
};

