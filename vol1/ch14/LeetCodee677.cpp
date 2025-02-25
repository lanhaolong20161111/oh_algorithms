struct TNode{                           //字典树结点类型
    TNode *ch[26];                  	//孩子结点指针
    int val;                         			//结点值
    TNode() {
        val=0;
        memset(ch,NULL,sizeof(ch));
    }
};
class MapSum {
    TNode * root;										//字典树的根结点
    unordered_map<string,int> cnt;				//计数器
public:
    MapSum() {
        root=new TNode();				//创建根结点
    }
    void insert(string key,int val) {
        int delta=val;
        if (cnt.count(key)) delta-=cnt[key];
        cnt[key]=val;
        TNode*p=root;
        for (auto c:key) {
            if (p->ch[c-'a']==NULL) {
                p->ch[c-'a']=new TNode();
            }
            p=p->ch[c-'a'];
            p->val+=delta;
        }
    }
    int sum(string prefix) {
        TNode*p=root;
        for (auto c:prefix) {
            if (p->ch[c-'a']==NULL) return 0;		//字典树中不存在时返回0
            else p=p->ch[c-'a'];							//继续向下查找
        }
        return p->val;										//找到后返回结点值
    }
};

