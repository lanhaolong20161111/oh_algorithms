class Solution {
public:
    unordered_set<string> dict;
    int ladderLength(string beginWord,string endWord,vector<string>&wordList) {
        for(auto s:wordList) dict.insert(s);
        if(!dict.count(endWord)) return 0;
        unordered_map<string,int> dist1,dist2;
        queue<string> qu1,qu2;
        qu1.push(beginWord);
        dist1[beginWord]=1;
        qu2.push(endWord);
        dist2[endWord]=1;
        while(qu1.size() && qu2.size()) {
            int ans;
            if(qu1.size()<=qu2.size())
                ans=extend(qu1,dist1,dist2);
            else
                ans=extend(qu2,dist2,dist1);
            if(ans>0) return ans;
        }
        return 0;
    }
    int extend(queue<string>&qu,unordered_map<string,int>&dist1,unordered_map<string,int>&dist2) {
        int cnt=qu.size();
        for(int k=0;k<cnt;k++) {
            auto str=qu.front();qu.pop();
            for(int i=0;i<str.size();i++) {
                string copystr=str;
                for(int j=0;j<26;j++) {
                    if('a'+j==str[i]) continue;
                    copystr[i]='a'+j;
                    if(dist2.count(copystr))    				//找到目标，查找成功
                        return dist1[str]+dist2[copystr];
                     if(dict.count(copystr)==0)
                        continue;
                    if(dist1.count(copystr)==1)
                        continue;
                    dist1[copystr]=dist1[str]+1;
                    qu.push(copystr);
                }
            }
        }
        return 0;													//查找不成功
    }
};

