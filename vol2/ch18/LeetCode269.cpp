class Solution {
public:
    string alienOrder(vector<string>& words) {
        set<pair<char,char>> myset;
        unordered_set<char> chars;      //存放所有字母
        vector<int> degree(256,0);        //存放入度
        queue<char> qu;
        for (const auto& word:words)    //提取所有不同的字母(含除重)
            chars.insert(word.begin(),word.end());
        for (int i=0;i<(int)words.size()-1;i++) {
            int minlen=min(words[i].size(),words[i+1].size());
            int j=0;
            for (;j<minlen;j++) {
                if (words[i][j]!=words[i+1][j]) {
                    myset.insert(pair<char,char>(words[i][j],words[i+1][j]));
                    break;          //存放words[i][j]<words[i+1][j]的关系(含除重)
                }
            }
            if (j==minlen && words[i].size()>words[i+1].size())
                return "";          //关系矛盾
        }
        for (const auto& e:myset)
            degree[e.second]++;    //求e.second的入度
        for (const auto& ch:chars) {
            if (degree[ch]==0) qu.push(ch);
        }
        string ans="";
        while (!qu.empty()) {
            auto ch=qu.front();qu.pop();     //出队字母ch
            ans+=ch;
            for (const auto& e:myset) {     //用e遍历myset
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

