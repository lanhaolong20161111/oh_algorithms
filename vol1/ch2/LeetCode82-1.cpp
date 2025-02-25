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
        int cnt[205];
        memset(cnt,0,sizeof(cnt));
        ListNode*p=head;
        while(p!=NULL) {
            cnt[100+p->val]++;
            p=p->next;
        }
        ListNode*h=new ListNode(-1),*r=h;
        p=head;
        while(p!=NULL) {
            if(cnt[100+p->val]==1) {    //结点p是非重复的
                r->next=p; r=p;
            }
            p=p->next;
        }
        r->next=NULL;               //尾结点的next置为空
         return h->next;
    }
};
