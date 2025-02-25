struct TNode{                           //字典树结点类型
    TNode *ch[26];                  //孩子结点指针
    int cnt;                            //表示该结点分支数
    bool isend;                     //标记是否为一个字符串结束处
    TNode() {
        isend=false;
        memset(ch,NULL,sizeof(ch));
    } 
};
class Trie {            //字典树类
    TNode*root;         //根结点
public:
    Trie() {
        root=new TNode();
    }
    void insert(string&s) {         //向字典树中插入字符串s
        TNode *p=root;
        for(int i=0;i<s.length();i++) {
            if(p->ch[s[i]-'a']==NULL) {
                p->ch[s[i]-'a']=new TNode();
            }
            p=p->ch[s[i]-'a'];
        }
        p->isend=true;
    }
    string search(string&s) {       //查找s的前缀
        TNode*p=root;
        string ans="";
        for(char c:s) {
            if(p->isend) return ans;
            if (p->ch[c-'a']==NULL) return "";
            ans+=c;
            p=p->ch[c-'a'];
        }
        return ans;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary,string sentence) {
        Trie tr;                //定义字典树对象
        for (auto s: dictionary)
            tr.insert(s);
        string ans;
        stringstream ssin(sentence);
        string word;
        while (ssin >> word){   //分离出单词word
            string str=tr.search(word);
            if (str=="") ans+=word+' ';
            else ans+=str+' ';
        }
        ans.pop_back();							//删除末尾添加的空格
        return ans;
    }
};

