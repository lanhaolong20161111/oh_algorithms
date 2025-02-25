/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode*r=head;            //β���ָ��
        ListNode*p=head->next;
        while(p!=NULL) {
            if(p->val!=r->val) {    //���p�Ƿ��ظ����
                r->next=p; r=p;
            }
            p=p->next;
        }
        r->next=NULL;               //β����next��Ϊ��
        return head;
    }
};
