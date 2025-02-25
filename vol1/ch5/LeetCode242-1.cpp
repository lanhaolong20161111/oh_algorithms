class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size())
            return false;
        unordered_map<char,int> hmap;
        for (char x:s)
            hmap[x]++;
        for (char y:t)
            hmap[y]--;
        for (auto z:hmap) {
            if (z.second!=0) return false;
        }
        return true;
    }
};

