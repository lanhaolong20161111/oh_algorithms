struct TNode{                           //字典树结点类型
    TNode *ch[26];                  //孩子结点指针
    int cnt;                            //表示该结点分支数
    TNode() {
        cnt=0;
        memset(ch,NULL,sizeof(ch));
    } 
};
class Trie {            //字典树类
    TNode*root;
public:
    Trie() {
        root=new TNode();       //创建根结点
    }
    void insert(string&s) {         //向字典树中插入字符串s
        TNode *p=root;
        for(int i=0;i<s.length();i++) {
            if(p->ch[s[i]-'a']==NULL) {
                p->ch[s[i]-'a']=new TNode();
            }
            p=p->ch[s[i]-'a'];
        }
        p->cnt++;
    }
    int dfs(TNode*root,string& s,int pos) { //深度优先搜索字典树
        int ans=0;
        if(root->cnt>0){
            ans+=root->cnt;
            root->cnt=0;            //避免重复查找
        }
        for(int k=0;k<26;k++) {
            if(root->ch[k]) {
                int nextpos=s.find('a'+k,pos);
                if(nextpos!=-1)
                    ans+=dfs(root->ch[k],s,nextpos+1);
            }
        }
        return ans;
    }
    int Count(string&s) {           //求字典树中s子序列的个数
        return dfs(root,s,0);
    }
};
class Solution {
public:
    int numMatchingSubseq(string s,vector<string>& words) {
        Trie tr;                //定义字典树对象
        for(int i=0;i<words.size();i++)
            tr.insert(words[i]);
        return tr.Count(s);
    }
};

