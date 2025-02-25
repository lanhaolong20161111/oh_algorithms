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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode*h=lists[0];
        for(int i=1;i<lists.size();i++) {
            h=merge(h,lists[i]);
        }
        return h;
    }
    ListNode*merge(ListNode* list1,ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode*h=new ListNode(-1),*r=h;
        ListNode*p=list1,*q=list2;
        while(p!=NULL && q!=NULL) {
            if(p->val<q->val) {
                r->next=p; r=p;
                p=p->next;
            }
            else {
                r->next=q; r=q;
                q=q->next;
            }
        }
        if(p!=NULL) r->next=p;
        else r->next=q;
        return h->next;
    }
};

