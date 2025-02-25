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
        ListNode*r=head;            //尾结点指针
        ListNode*p=head->next;
        while(p!=NULL) {
            if(p->val!=r->val) {    //结点p是非重复结点
                r->next=p; r=p;
            }
            p=p->next;
        }
        r->next=NULL;               //尾结点的next置为空
        return head;
    }
};
