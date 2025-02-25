class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hset1,hset2;
        for (int x:nums1)
            hset1.insert(x);
        for (int y:nums2)
            hset2.insert(y);
        return intersection(hset1,hset2);
    }

    vector<int> intersection(unordered_set<int>&hset1,unordered_set<int>&hset2) {
        if (hset1.size()>hset2.size()) {
            return intersection(hset2,hset1);
        }
        vector<int> ans;
        for (int x:hset1) {
            if (hset2.count(x)) ans.push_back(x);
        }
        return ans;
    }
};

