class Solution {
public:
    ListNode* mergeTwoLists(ListNode*list1,ListNode*list2) {
        return merge(list1,list2);
    }
    ListNode* merge(ListNode*a,ListNode*b) {
        if(a==NULL) return b;
        if(b==NULL) return a;
        if(a->val<b->val) {
            a->next=merge(a->next,b);
            return a;
        }
        else {
            b->next=merge(a,b->next);
            return b;
        }
    }
};

