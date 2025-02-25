struct Node {                           //˫����������
  int key,val;
  Node *left,*right;                    //����ǰ��ָ��
  Node(int k,int v): key(k),val(v),left(NULL),right(NULL) {}
};
class LRUCache {
      Node *head,*tail;                         //˫�������β���
      unordered_map<int, Node*> hmap;         //��Źؼ��ֶ�Ӧ�Ľ���ַ
      int n;                                //LRU������
public:
  LRUCache(int capacity) {                  //��ʼ��
    n=capacity;
    head=new Node(-1,-1);tail=new Node(-1,-1);
    head->right=tail;tail->left=head;         //�����յ�˫����
  }
  int get(int key) {                        //���عؼ���key��ֵ
    if (hmap.count(key)==0) return -1;    //û���ҵ�key����-1
    Node* p=hmap[key];                  //�ҵ�key�Ľ��p
    remove(p);                          //ɾ�����p
    insert(p);                          //�����p���뵽�ײ�
    return p->val;                        //���ؽ��ֵ
  }
  void put(int key, int value) {                //����<�ؼ���,ֵ>
    if (hmap.count(key)) {                  //�ҵ�key�����
      Node* p=hmap[key];                //�ҵ�key�Ľ��p
      p->val=value;                     //����Ϊ��ֵ
      remove(p);                        //ɾ�����p
      insert(p);                        //�����p���뵽�ײ�
    }
    else {                              //û���ҵ�key�����
      if (hmap.size()==n) {               //�����
        Node* p=tail->left;               //�ҵ�ĩβ���p
        remove(p);                      //ɾ�����p
        hmap.erase(p->key);             //��hmap��ɾ��p->key
        delete p;                       //�ͷŽ��p�Ŀռ�
      }
      Node* p=new Node(key,value);        //�½�Ϊ<key,value>�Ľ��p
      hmap[key]=p;                      //��key���뵽hmap
      insert(p);                        //�����p���뵽�ײ�
    }
  }
private:
  void remove(Node* p) {                  //��˫������ɾ�����p
    p->right->left=p->left;
    p->left->right=p->right;
  }
  void insert(Node* p) {                    //�����p���뵽�ײ�
    p->right=head->right;
    p->left=head;
    head->right->left=p;
    head->right=p;
  }
};

