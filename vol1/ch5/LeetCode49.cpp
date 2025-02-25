class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hmap;
        for(string x:strs) {
            string key=x;
            sort(key.begin(),key.end());
            hmap[key].push_back(x);
        }
        vector<vector<string>> ans;         //´æ·Å´ð°¸
        for(auto x:hmap) {
            ans.push_back(x.second);
        }
        return ans;
    }
};

