class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(head->next==NULL) return head;  //ֻ��һ�����
        ListNode* p=removeNodes(head->next);    //���ص�����ͷһ��������
        if(head->val<p->val){
            delete head;
            return p;           //ɾ�� head���
        }
        else {
            head->next=p;                      //����head���
            return head;
        }
    }
};

