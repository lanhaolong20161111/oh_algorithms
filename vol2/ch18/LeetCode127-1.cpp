class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        unordered_set<string> dict;     //字典用dict表示
        unordered_set<string> visited;  //是否访问过
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
                string str=qu.front(); qu.pop();    //出队str
                for(int i=0;i<str.size();i++) {     //对str每个字符进行改变
                    string copystr=str;
                    for(int j=0;j<26;j++) {
                        copystr[i]='a'+j;
                        if(copystr==endWord)
                            return ans+1;
                        if(dict.count(copystr)==0)
                            continue;               //copystr不在字典中时跳过
                        if(visited.count(copystr))
                            continue;               //copystr已访问过时跳过
                        qu.push(copystr);
                        visited.insert(copystr);
                    }
                }
            }
        }
        return 0;
    }
};

