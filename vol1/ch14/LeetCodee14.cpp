struct TNode{                           //�ֵ����������
    TNode *ch[26];                  //���ӽ��ָ��
    int cnt;                            //��ʾ�ý���֧��
    bool isend;                     //����Ƿ�Ϊһ���ַ���������
    TNode() {
        cnt=0;
        isend=false;
        memset(ch,NULL,sizeof(ch));
    } 
};
class Trie {            		//�ֵ�����
    TNode*root;         	//�����
public:
    Trie() {
        root=new TNode();				//���������
    }
    void insert(string&s) {         //���ֵ����в����ַ���s
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
    string maxprefix() {					//�������ǰ׺
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
        Trie tr;										//�����ֵ�������
        for(int i=0;i<strs.size();i++) {
            if(strs[i].empty()) return "";
            tr.insert(strs[i]);
        }
        return tr.maxprefix();
    }
};

