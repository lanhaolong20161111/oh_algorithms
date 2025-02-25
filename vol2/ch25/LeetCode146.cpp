struct Node {                           //双链表结点类型
  int key,val;
  Node *left,*right;                    //结点的前后指针
  Node(int k,int v): key(k),val(v),left(NULL),right(NULL) {}
};
class LRUCache {
      Node *head,*tail;                         //双链表的首尾结点
      unordered_map<int, Node*> hmap;         //存放关键字对应的结点地址
      int n;                                //LRU的容量
public:
  LRUCache(int capacity) {                  //初始化
    n=capacity;
    head=new Node(-1,-1);tail=new Node(-1,-1);
    head->right=tail;tail->left=head;         //创建空的双链表
  }
  int get(int key) {                        //返回关键字key的值
    if (hmap.count(key)==0) return -1;    //没有找到key返回-1
    Node* p=hmap[key];                  //找到key的结点p
    remove(p);                          //删除结点p
    insert(p);                          //将结点p插入到首部
    return p->val;                        //返回结点值
  }
  void put(int key, int value) {                //插入<关键字,值>
    if (hmap.count(key)) {                  //找到key的情况
      Node* p=hmap[key];                //找到key的结点p
      p->val=value;                     //设置为新值
      remove(p);                        //删除结点p
      insert(p);                        //将结点p插入到首部
    }
    else {                              //没有找到key的情况
      if (hmap.size()==n) {               //上溢出
        Node* p=tail->left;               //找到末尾结点p
        remove(p);                      //删除结点p
        hmap.erase(p->key);             //从hmap中删除p->key
        delete p;                       //释放结点p的空间
      }
      Node* p=new Node(key,value);        //新建为<key,value>的结点p
      hmap[key]=p;                      //将key插入到hmap
      insert(p);                        //将结点p插入到首部
    }
  }
private:
  void remove(Node* p) {                  //从双链表中删除结点p
    p->right->left=p->left;
    p->left->right=p->right;
  }
  void insert(Node* p) {                    //将结点p插入到首部
    p->right=head->right;
    p->left=head;
    head->right->left=p;
    head->right=p;
  }
};

