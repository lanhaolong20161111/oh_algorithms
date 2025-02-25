struct TNode{                           //�ֵ����������
    TNode *ch[26];                  //���ӽ��ָ��
    int cnt;                            //��ʾ�ý���֧��
    bool isend;                     //����Ƿ�Ϊһ���ַ���������
    TNode() {
        isend=false;
        memset(ch,NULL,sizeof(ch));
    } 
};
class Trie {            //�ֵ�����
    TNode*root;         //�����
public:
    Trie() {
        root=new TNode();
    }
    void insert(string&s) {         //���ֵ����в����ַ���s
        TNode *p=root;
        for(int i=0;i<s.length();i++) {
            if(p->ch[s[i]-'a']==NULL) {
                p->ch[s[i]-'a']=new TNode();
            }
            p=p->ch[s[i]-'a'];
        }
        p->isend=true;
    }
    string search(string&s) {       //����s��ǰ׺
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
        Trie tr;                //�����ֵ�������
        for (auto s: dictionary)
            tr.insert(s);
        string ans;
        stringstream ssin(sentence);
        string word;
        while (ssin >> word){   //���������word
            string str=tr.search(word);
            if (str=="") ans+=word+' ';
            else ans+=str+' ';
        }
        ans.pop_back();							//ɾ��ĩβ��ӵĿո�
        return ans;
    }
};

