class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size()!=t.size())
            return false;
        unordered_map<char,int> hmap1;
        unordered_map<char,int> hmap2;
        for (int i=0;i<s.size();i++) {
            char x=s[i],y=t[i];
            if(hmap1.count(x)==0 && hmap2.count(y)==0) {
                hmap1[x]=y;
                hmap2[y]=x;
            }
            else if (hmap1.count(x)==1 && hmap1[x]!=y || hmap2.count(y)==1 && hmap2[y]!=x)
                return false;								//²»Æ¥Åä·µ»Øfalse
        }
        return true;
    }
};

