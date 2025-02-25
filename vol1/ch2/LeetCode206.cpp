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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode*h=new ListNode();    		 //创建头结点h
        ListNode*p=head,*tmp;
        while(p!=NULL) {
            tmp=p->next;
            p->next=h->next;
            h->next=p;
            p=tmp;
        }
        return h->next;
    }
};
