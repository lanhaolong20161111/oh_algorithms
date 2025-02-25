class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node*h=new Node(-1);
        h->next=head;               //为了方便添加一个头结点
		Node *p=h->next;
        while(p!=NULL) {						//建立双结点的单链表h
            Node*q=new Node(p->val);		//建立结点p的复制结点q
            q->next=p->next;					//将结点q插入在结点p之后
            p->next=q;
            p=q->next;
        }
        p=h->next;
        while(p!=NULL) {					//修改复制结点的random
            if(p->random!=NULL) {
                p->next->random=p->random->next;
            }
            p=p->next->next;
        }
        Node*r=h;		                    //h为复制单链表的头结点
	    p=h->next;
        while(p!=NULL) {
            Node*q=p->next;					//q指向复制结点
			p->next=q->next;				//删除结点q
			r->next=q; r=q;
			p=p->next;
		}
        r->next=NULL;
        return h->next;
    }
};

