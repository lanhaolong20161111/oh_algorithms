class Solution {
public:
    bool canConstruct(string s,string t) {
        if (s.size()>t.size())
            return false;
        unordered_map<char,int> hmap;
        for (char x:t)
            hmap[x]++;
        for (char y:s)
            hmap[y]--;
        for (auto z:hmap) {
            if (z.second<0) return false;
        }
        return true;
    }
};

