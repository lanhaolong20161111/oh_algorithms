struct QNode {                                          //优先队列中结点类型
    int val;                                            //当前元素 
    int i;                                                  //当前元素所在链表序号
    bool operator<(const QNode&s) const {
        return val>s.val;                                   //按val越小越优先出队
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0) return NULL;
        ListNode*h=new ListNode(-1),*r=h;
        QNode e,e1;
        priority_queue<QNode> pq;
        for(int i=0;i<k;i++) {
            if(lists[i]!=NULL) {
                e.val=lists[i]->val;
                e.i=i;
                pq.push(e);
            }
        }
        while(!pq.empty()) {
            e=pq.top(); pq.pop();
            int mini=e.i;
            r->next=lists[mini]; r=lists[mini];
            lists[mini]=lists[mini]->next;
            if(lists[mini]!=NULL) {
                e1.val=lists[mini]->val;
                e1.i=mini;
                pq.push(e1);
            }
        }
        return h->next;
    }
};

