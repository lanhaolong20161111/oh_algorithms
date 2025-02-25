class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums,int k) {
        unordered_map<int,int> hmap;
        int n=nums.size();
        for (int i=0;i<n;i++) {
            int d=nums[i];
            if (hmap.count(d)==1 && i-hmap[d]<=k)
                return true;
            else
                hmap[d]=i;
        }
        return false;
    }
};

