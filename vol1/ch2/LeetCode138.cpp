class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node*h=new Node(-1);
        h->next=head;               //Ϊ�˷������һ��ͷ���
		Node *p=h->next;
        while(p!=NULL) {						//����˫���ĵ�����h
            Node*q=new Node(p->val);		//�������p�ĸ��ƽ��q
            q->next=p->next;					//�����q�����ڽ��p֮��
            p->next=q;
            p=q->next;
        }
        p=h->next;
        while(p!=NULL) {					//�޸ĸ��ƽ���random
            if(p->random!=NULL) {
                p->next->random=p->random->next;
            }
            p=p->next->next;
        }
        Node*r=h;		                    //hΪ���Ƶ������ͷ���
	    p=h->next;
        while(p!=NULL) {
            Node*q=p->next;					//qָ���ƽ��
			p->next=q->next;				//ɾ�����q
			r->next=q; r=q;
			p=p->next;
		}
        r->next=NULL;
        return h->next;
    }
};

