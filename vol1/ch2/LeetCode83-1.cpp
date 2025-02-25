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
        ListNode*pre=head,*p=pre->next;
        while(p!=NULL) {
            if(p->val==pre->val) {
                pre->next=p->next;  //删除结点p
                delete p;
                p=pre->next;
            }
            else {
                pre=pre->next;      //pre,p同步后移
                p=pre->next;
            }
        }
        return head;
    }
};
