struct TNode{                           //字典树结点类型
    TNode *ch[26];                  //孩子结点指针
    int cnt;                            //表示该结点分支数
    bool isend;                     //标记是否为一个字符串结束处
    TNode() {
        cnt=0;
        isend=false;
        memset(ch,NULL,sizeof(ch));
    } 
};
class Trie {            		//字典树类
    TNode*root;         	//根结点
public:
    Trie() {
        root=new TNode();				//创建根结点
    }
    void insert(string&s) {         //向字典树中插入字符串s
        TNode *p=root;
        for(int i=0;i<s.length();i++) {
            if(p->ch[s[i]-'a']==NULL) {
                p->ch[s[i]-'a']=new TNode();
                p->cnt++;
            }
            p=p->ch[s[i]-'a'];
        }
        p->isend=true;
    }
    string maxprefix() {					//查找最大前缀
        string ans="";
        TNode *p=root;
        int k;
        while(p->cnt==1 && p->isend==false) {
            for(k=0;k<26;k++) {
                if(p->ch[k]!=NULL) {
                    ans+=char(k+'a');
                    break;
                }
            }
            p=p->ch[k];
        }
        return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie tr;										//定义字典树对象
        for(int i=0;i<strs.size();i++) {
            if(strs[i].empty()) return "";
            tr.insert(strs[i]);
        }
        return tr.maxprefix();
    }
};

