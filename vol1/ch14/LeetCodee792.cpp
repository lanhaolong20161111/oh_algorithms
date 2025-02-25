struct TNode{                           //�ֵ����������
    TNode *ch[26];                  //���ӽ��ָ��
    int cnt;                            //��ʾ�ý���֧��
    TNode() {
        cnt=0;
        memset(ch,NULL,sizeof(ch));
    } 
};
class Trie {            //�ֵ�����
    TNode*root;
public:
    Trie() {
        root=new TNode();       //���������
    }
    void insert(string&s) {         //���ֵ����в����ַ���s
        TNode *p=root;
        for(int i=0;i<s.length();i++) {
            if(p->ch[s[i]-'a']==NULL) {
                p->ch[s[i]-'a']=new TNode();
            }
            p=p->ch[s[i]-'a'];
        }
        p->cnt++;
    }
    int dfs(TNode*root,string& s,int pos) { //������������ֵ���
        int ans=0;
        if(root->cnt>0){
            ans+=root->cnt;
            root->cnt=0;            //�����ظ�����
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
    int Count(string&s) {           //���ֵ�����s�����еĸ���
        return dfs(root,s,0);
    }
};
class Solution {
public:
    int numMatchingSubseq(string s,vector<string>& words) {
        Trie tr;                //�����ֵ�������
        for(int i=0;i<words.size();i++)
            tr.insert(words[i]);
        return tr.Count(s);
    }
};

