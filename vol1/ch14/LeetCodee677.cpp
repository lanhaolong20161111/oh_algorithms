struct TNode{                           //�ֵ����������
    TNode *ch[26];                  	//���ӽ��ָ��
    int val;                         			//���ֵ
    TNode() {
        val=0;
        memset(ch,NULL,sizeof(ch));
    }
};
class MapSum {
    TNode * root;										//�ֵ����ĸ����
    unordered_map<string,int> cnt;				//������
public:
    MapSum() {
        root=new TNode();				//���������
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
            if (p->ch[c-'a']==NULL) return 0;		//�ֵ����в�����ʱ����0
            else p=p->ch[c-'a'];							//�������²���
        }
        return p->val;										//�ҵ��󷵻ؽ��ֵ
    }
};

