struct TNode{                           //�ֵ����������
    TNode *ch[26];                  //���ӽ��ָ��
    bool isend;                     //����Ƿ�Ϊһ���ַ���������
    TNode() {
        isend=false;
        memset(ch,NULL,sizeof(ch));
    } 
};
class Trie {					//�ֵ�����
    TNode*root;         //�����
     TNode* searchPrefix(string s) {
        TNode*p=root;
        for (char c:s) {
            if(p->ch[c-'a']==NULL) return NULL;
            p=p->ch[c-'a'];
        }
        return p;
    }
public:
    Trie() {
        root=new TNode();				//���������
    }
    void insert(string word) {
        TNode*p=root;
        for(int i=0;i<word.length();i++) {
            if(p->ch[word[i]-'a']==NULL) {
                p->ch[word[i]-'a']=new TNode();
            }
            p=p->ch[word[i]-'a'];
        }
        p->isend=true;
    }
    bool search(string word) {
        TNode* p=searchPrefix(word);
        return p!=NULL && p->isend==true;
    }
        bool startsWith(string prefix) {
        return searchPrefix(prefix)!=NULL;
    }
};

