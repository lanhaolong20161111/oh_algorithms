class Solution {
public:
    string destCity(vector<vector<string>> &paths) {
        unordered_set<string> hset;
        for (auto x:paths)
            hset.insert(x[0]);
        for (auto x:paths) {
            if (hset.count(x[1])==0)
                return x[1];
        }
        return "";
    }
};

