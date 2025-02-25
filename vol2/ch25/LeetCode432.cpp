struct DNode {              //双链表结点类型
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
        head=new DNode();       //建立头结点
        tail=new DNode();       //建立尾结点
        head->next=tail;
        tail->prior=head;
    }

    void insprenode(DNode*p,DNode*s) {  //将结点s插入在结点p之前
        p->prior->next=s;
        s->prior=p->prior;
        s->next=p;
        p->prior=s;
    }

    void inc(string key) {
        if(hmap.count(key)==0) {        //key不在数据结构中
            if(tail->prior==head || tail->prior->cnt>1) {   //链表空或尾结点cnt>1
                DNode*s=new DNode();    //新建次数为1的结点
                s->cnt=1;
                s->hset.insert(key);
                insprenode(tail,s);       //将结点s插入在结点tail之前
                hmap[key]=s;                //设置hmap[key]
            }
            else if(tail->prior->cnt==1) {     //链表不空且尾结点cnt=1
                DNode*p=tail->prior;            //p指向尾结点
                p->hset.insert(key);            //在尾结点中插入key
                hmap[key]=p;                     //重置hmap[key]
            }
        }
        else {                          //key在数据结构中
            DNode*p=hmap[key];          //找到在链表中的结点p
            hmap.erase(key);            //从hmap中删除key
            p->hset.erase(key);         //从结点p的字符串列表中删除key
            DNode*pre=p->prior;
            if(pre==head || pre->cnt>p->cnt+1) {    //到头了或前面结点不适合插入
                DNode*s=new DNode();            //新建结点s
                s->cnt=p->cnt+1;
                s->hset.insert(key);
                insprenode(p,s);                //将结点s插入在结点p之前
                hmap[key]=s;                    //重置hmap[key]
            }
            else if(pre!=head && pre->cnt==p->cnt+1) {  //没到头且前面结点适合插入
                pre->hset.insert(key);          //在结点pre中插入key
                hmap[key]=pre;
            }
            if(p->hset.size()==0) {     //结点p为空时删除
                delnode(p);             //从链表中删除结点p
            }
        }
    }
    
    void delnode(DNode*p) {     //在双链表中删除结点p
        p->next->prior=p->prior;
        p->prior->next=p->next;
        delete p;
    }
    void inspostnode(DNode*p,DNode*s) {  //将结点s插入在结点p之后
        p->next->prior=s;
        s->next=p->next;
        p->next=s;
        s->prior=p;
    }

    void dec(string key) {
        DNode*p=hmap[key];          //找到key的结点p
        hmap.erase(key);            //从hmap中删除key
        p->hset.erase(key);         //从结点p的字符串列表中删除key
        DNode*post=p->next;
        if(p->cnt==1) {                 //原次数为1的特殊情况
            if(p->hset.size()==0) {     //结点p为空时删除
                delnode(p);             //从链表中删除结点p
            }
        }
        else {
            if(post==tail || post->cnt<p->cnt-1) {    //到尾了或后面结点不适合插入
                DNode*s=new DNode();            //新建结点s
                s->cnt=p->cnt-1;
                s->hset.insert(key);
                inspostnode(p,s);               //将结点s插入在结点p之后
                hmap[key]=s;                    //重置hmap[key]
            }
            else if(post!=tail && post->cnt==p->cnt-1) {  //没到头且前面结点适合插入
                post->hset.insert(key);          //在结点post中插入key
                hmap[key]=post;
            }
            if(p->hset.size()==0) {     //结点p为空时删除
                delnode(p);             //从链表中删除结点p
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

