struct SNode {                          //������������
    int key;    //����
    int val;    //ֵ
    SNode *next;    //��һ�����ָ��
    SNode() {}
    SNode(int k,int v):key(k),val(v),next(NULL) {}
};

class MyHashMap {
private:
    const static int MAXH=997;       //��ϣ����
    SNode *ht[MAXH];
    SNode* search(int key) {      //����Ϊkey�Ľ��,û��ʱ����NULL
        int d=key%MAXH;                    //�����ϣ����ֵ
        SNode *p=ht[d];                    //pָ��ht[d]��������׽��
        while(p!=NULL && p->key!=key)           //����ht[d]������
            p=p->next;
        return p;
    }
public:
    MyHashMap() {
        memset(ht,NULL,sizeof(ht));
    }
    
    void put(int key,int value) {
        SNode* p=search(key);
        if(p!=NULL)
            p->val=value;
        else {        
            int d=key%MAXH;                                 //�����ϣ����ֵ
            SNode *q=new SNode(key,value);              //�½����q���key
            if (ht[d]==NULL)                            //��������ht[d]Ϊ��
                ht[d]=q;
            else {                                      //��������ht[d]����
                q->next=ht[d];                          //����ͷ�巨���뵽ha[adr]�ĵ�������
                ht[d]=q;
            }
        }
    }
      
    int get(int key) {
        SNode* p=search(key);
        if(p!=NULL)                             //�ҵ�Ϊkey�Ľ��
            return p->val;
        else                                    //û���ҵ�Ϊkey�Ľ��
            return -1;
    }
    
    void remove(int key) {
        SNode *pre,*p;
        int d=key % MAXH;                                       //�����ϣ����ֵ
        pre=ht[d];                                 //preָ��ht[d]��������׽��
        if(pre==NULL) return;
        if(pre->key==key) {                               //���pre��Ҫɾ���Ľ��
            ht[d]=pre->next;
            delete pre;
        }
        else {                                               //����key���p
            p=pre->next;
            while(p!=NULL && p->key!=key) {
                pre=p;
                p=p->next;
            }
            if(p!=NULL) {
                pre->next=p->next;
                delete p;
            }
        }
    }
};

