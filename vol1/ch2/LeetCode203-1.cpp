class Solution {
public:
    ListNode* removeElements(ListNode* head,int val) {
        ListNode*p=head,*tmp;
        while(p!=NULL && p->val==val) {     //删除开头的所有val结点
            tmp=p->next;
            delete p;
            p=tmp;
        }                                   							//循环结束后p指向第一个不等于val的结点
        if(p==NULL) return NULL;
        head=p;                             						//结点p为结果单链表的首结点
        ListNode*pre=p;                     				//设置双指针pre,p
        p=p->next;
        while(p!=NULL) {                   				 //用p遍历剩余结点
            if(p->val==val) {               				//结点p为被删结点
                pre->next=p->next;
                delete p;
                p=pre->next;
            }
            else {                          						//结点p不为被删结点
                pre=p;                      						//pre,p同步后移
                p=pre->next;
            }
        }
        return head;
    }
};
