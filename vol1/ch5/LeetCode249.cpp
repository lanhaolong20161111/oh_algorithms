class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        string key;
        unordered_map<string,vector<string>> hmap;
        for(string x:strings) {
            key="";
            for(int i=1;i<x.size();i++)
                key+=(x[i]-x[0]+26)%26;     //当前字符与首字符的距离
            hmap[key].push_back(x);
        }
        vector<vector<string>> ans;         //存放答案
        for(auto x:hmap) {
            ans.push_back(x.second);
        }
        return ans;
    }
};

