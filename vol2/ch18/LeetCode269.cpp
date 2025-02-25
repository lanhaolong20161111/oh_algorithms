class Solution {
public:
    string alienOrder(vector<string>& words) {
        set<pair<char,char>> myset;
        unordered_set<char> chars;      //���������ĸ
        vector<int> degree(256,0);        //������
        queue<char> qu;
        for (const auto& word:words)    //��ȡ���в�ͬ����ĸ(������)
            chars.insert(word.begin(),word.end());
        for (int i=0;i<(int)words.size()-1;i++) {
            int minlen=min(words[i].size(),words[i+1].size());
            int j=0;
            for (;j<minlen;j++) {
                if (words[i][j]!=words[i+1][j]) {
                    myset.insert(pair<char,char>(words[i][j],words[i+1][j]));
                    break;          //���words[i][j]<words[i+1][j]�Ĺ�ϵ(������)
                }
            }
            if (j==minlen && words[i].size()>words[i+1].size())
                return "";          //��ϵì��
        }
        for (const auto& e:myset)
            degree[e.second]++;    //��e.second�����
        for (const auto& ch:chars) {
            if (degree[ch]==0) qu.push(ch);
        }
        string ans="";
        while (!qu.empty()) {
            auto ch=qu.front();qu.pop();     //������ĸch
            ans+=ch;
            for (const auto& e:myset) {     //��e����myset
                if (e.first==ch) {
                    degree[e.second]--;
                    if (degree[e.second]==0) {
                        qu.push(e.second);
                    }
                }
            }
        }
        return ans.size()==chars.size() ? ans:"";
    }
};

