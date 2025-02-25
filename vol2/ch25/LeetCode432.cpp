struct DNode {              //˫����������
    int cnt;
    unordered_set<string> hset;
    DNode *prior,*next;
    DNode():prior(NULL), next(NULL) {};
};

class AllOne {
    unordered_map<string,DNode*> hmap;
    DNode*head,*tail;
public:
    AllOne() {
        head=new DNode();       //����ͷ���
        tail=new DNode();       //����β���
        head->next=tail;
        tail->prior=head;
    }

    void insprenode(DNode*p,DNode*s) {  //�����s�����ڽ��p֮ǰ
        p->prior->next=s;
        s->prior=p->prior;
        s->next=p;
        p->prior=s;
    }

    void inc(string key) {
        if(hmap.count(key)==0) {        //key�������ݽṹ��
            if(tail->prior==head || tail->prior->cnt>1) {   //����ջ�β���cnt>1
                DNode*s=new DNode();    //�½�����Ϊ1�Ľ��
                s->cnt=1;
                s->hset.insert(key);
                insprenode(tail,s);       //�����s�����ڽ��tail֮ǰ
                hmap[key]=s;                //����hmap[key]
            }
            else if(tail->prior->cnt==1) {     //��������β���cnt=1
                DNode*p=tail->prior;            //pָ��β���
                p->hset.insert(key);            //��β����в���key
                hmap[key]=p;                     //����hmap[key]
            }
        }
        else {                          //key�����ݽṹ��
            DNode*p=hmap[key];          //�ҵ��������еĽ��p
            hmap.erase(key);            //��hmap��ɾ��key
            p->hset.erase(key);         //�ӽ��p���ַ����б���ɾ��key
            DNode*pre=p->prior;
            if(pre==head || pre->cnt>p->cnt+1) {    //��ͷ�˻�ǰ���㲻�ʺϲ���
                DNode*s=new DNode();            //�½����s
                s->cnt=p->cnt+1;
                s->hset.insert(key);
                insprenode(p,s);                //�����s�����ڽ��p֮ǰ
                hmap[key]=s;                    //����hmap[key]
            }
            else if(pre!=head && pre->cnt==p->cnt+1) {  //û��ͷ��ǰ�����ʺϲ���
                pre->hset.insert(key);          //�ڽ��pre�в���key
                hmap[key]=pre;
            }
            if(p->hset.size()==0) {     //���pΪ��ʱɾ��
                delnode(p);             //��������ɾ�����p
            }
        }
    }
    
    void delnode(DNode*p) {     //��˫������ɾ�����p
        p->next->prior=p->prior;
        p->prior->next=p->next;
        delete p;
    }
    void inspostnode(DNode*p,DNode*s) {  //�����s�����ڽ��p֮��
        p->next->prior=s;
        s->next=p->next;
        p->next=s;
        s->prior=p;
    }

    void dec(string key) {
        DNode*p=hmap[key];          //�ҵ�key�Ľ��p
        hmap.erase(key);            //��hmap��ɾ��key
        p->hset.erase(key);         //�ӽ��p���ַ����б���ɾ��key
        DNode*post=p->next;
        if(p->cnt==1) {                 //ԭ����Ϊ1���������
            if(p->hset.size()==0) {     //���pΪ��ʱɾ��
                delnode(p);             //��������ɾ�����p
            }
        }
        else {
            if(post==tail || post->cnt<p->cnt-1) {    //��β�˻�����㲻�ʺϲ���
                DNode*s=new DNode();            //�½����s
                s->cnt=p->cnt-1;
                s->hset.insert(key);
                inspostnode(p,s);               //�����s�����ڽ��p֮��
                hmap[key]=s;                    //����hmap[key]
            }
            else if(post!=tail && post->cnt==p->cnt-1) {  //û��ͷ��ǰ�����ʺϲ���
                post->hset.insert(key);          //�ڽ��post�в���key
                hmap[key]=post;
            }
            if(p->hset.size()==0) {     //���pΪ��ʱɾ��
                delnode(p);             //��������ɾ�����p
            }
        }
    }
    
    string getMaxKey() {
        if(hmap.size()==0)
            return "";
        else
            return *head->next->hset.begin();
     }
    
    string getMinKey() {
        if(hmap.size()==0)
            return "";
        else
            return *tail->prior->hset.begin();
    }
};

