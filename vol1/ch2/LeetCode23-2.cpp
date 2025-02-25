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
    const int INF=10010;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0) return NULL;
        ListNode*h=new ListNode(-1),*r=h;
        int x[k];
        for(int i=0;i<k;i++) {
            if(lists[i]!=NULL) x[i]=lists[i]->val;
            else x[i]=INF;
        }
        while(true) {
            int mini=mink(x,k);
            if(mini==-1) break;
            r->next=lists[mini]; r=lists[mini];
            lists[mini]=lists[mini]->next;
            if(lists[mini]!=NULL)
                x[mini]=lists[mini]->val;
            else
                x[mini]=INF;

        }
        return h->next;
    }
    int mink(int x[],int k) {       //求最小值的段号
        int mini=0;
        for(int i=1;i<k;i++) {
            if(x[i]<x[mini])
                mini=i;
        }
        if(x[mini]==INF) return -1;
        else return mini;
    }
};

