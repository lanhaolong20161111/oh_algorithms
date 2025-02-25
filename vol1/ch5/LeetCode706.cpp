struct SNode {                          //单链表结点类型
    int key;    //键域
    int val;    //值
    SNode *next;    //下一个结点指针
    SNode() {}
    SNode(int k,int v):key(k),val(v),next(NULL) {}
};

class MyHashMap {
private:
    const static int MAXH=997;       //哈希表长度
    SNode *ht[MAXH];
    SNode* search(int key) {      //查找为key的结点,没有时返回NULL
        int d=key%MAXH;                    //计算哈希函数值
        SNode *p=ht[d];                    //p指向ht[d]单链表的首结点
        while(p!=NULL && p->key!=key)           //遍历ht[d]单链表
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
            int d=key%MAXH;                                 //计算哈希函数值
            SNode *q=new SNode(key,value);              //新建结点q存放key
            if (ht[d]==NULL)                            //若单链表ht[d]为空
                ht[d]=q;
            else {                                      //若单链表ht[d]不空
                q->next=ht[d];                          //采用头插法插入到ha[adr]的单链表中
                ht[d]=q;
            }
        }
    }
      
    int get(int key) {
        SNode* p=search(key);
        if(p!=NULL)                             //找到为key的结点
            return p->val;
        else                                    //没有找到为key的结点
            return -1;
    }
    
    void remove(int key) {
        SNode *pre,*p;
        int d=key % MAXH;                                       //计算哈希函数值
        pre=ht[d];                                 //pre指向ht[d]单链表的首结点
        if(pre==NULL) return;
        if(pre->key==key) {                               //结点pre是要删除的结点
            ht[d]=pre->next;
            delete pre;
        }
        else {                                               //查找key结点p
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

