struct TNode{                           //字典树结点类型
    TNode *ch[26];                  //孩子结点指针
    bool isend;                     //标记是否为一个字符串结束处
    TNode() {
        isend=false;
        memset(ch,NULL,sizeof(ch));
    } 
};
class Trie {					//字典树类
    TNode*root;         //根结点
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
        root=new TNode();				//创建根结点
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

