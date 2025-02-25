class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> hmap;
        for (int x:target)
            hmap[x]++;
        for (int y:arr) {
            if (--hmap[y]<0)
                return false;
        }
        return true;
    }
};

