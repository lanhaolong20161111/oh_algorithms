class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(head->next==NULL) return head;  //只有一个结点
        ListNode* p=removeNodes(head->next);    //返回的链表头一定是最大的
        if(head->val<p->val){
            delete head;
            return p;           //删除 head结点
        }
        else {
            head->next=p;                      //保留head结点
            return head;
        }
    }
};

