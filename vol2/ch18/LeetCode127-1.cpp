class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        unordered_set<string> dict;     //�ֵ���dict��ʾ
        unordered_set<string> visited;  //�Ƿ���ʹ�
        for(auto s:wordList) dict.insert(s);
        if(!dict.count(endWord)) return 0;
        queue<string> qu;
        qu.push(beginWord);
        visited.insert(beginWord);
        int ans=0;
        while(!qu.empty()) {
            ans++;
            int cnt=qu.size();
            for(int k=0;k<cnt;k++) {
                string str=qu.front(); qu.pop();    //����str
                for(int i=0;i<str.size();i++) {     //��strÿ���ַ����иı�
                    string copystr=str;
                    for(int j=0;j<26;j++) {
                        copystr[i]='a'+j;
                        if(copystr==endWord)
                            return ans+1;
                        if(dict.count(copystr)==0)
                            continue;               //copystr�����ֵ���ʱ����
                        if(visited.count(copystr))
                            continue;               //copystr�ѷ��ʹ�ʱ����
                        qu.push(copystr);
                        visited.insert(copystr);
                    }
                }
            }
        }
        return 0;
    }
};

