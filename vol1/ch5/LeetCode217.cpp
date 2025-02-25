class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hset;
        for(int x:nums) {
            if(hset.count(x)==1)
                return true;
            hset.insert(x);
        }
        return false;
    }
};

