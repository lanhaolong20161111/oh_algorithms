class Solution {
public:
    ListNode* removeElements(ListNode* head,int val) {
        ListNode*p=head,*tmp;
        while(p!=NULL && p->val==val) {     //ɾ����ͷ������val���
            tmp=p->next;
            delete p;
            p=tmp;
        }                                   							//ѭ��������pָ���һ��������val�Ľ��
        if(p==NULL) return NULL;
        head=p;                             						//���pΪ�����������׽��
        ListNode*pre=p;                     				//����˫ָ��pre,p
        p=p->next;
        while(p!=NULL) {                   				 //��p����ʣ����
            if(p->val==val) {               				//���pΪ��ɾ���
                pre->next=p->next;
                delete p;
                p=pre->next;
            }
            else {                          						//���p��Ϊ��ɾ���
                pre=p;                      						//pre,pͬ������
                p=pre->next;
            }
        }
        return head;
    }
};
