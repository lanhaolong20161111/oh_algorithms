class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if (n<2) return false;
        unordered_map<int,int> hmap;
        hmap[0]=-1;
        int presum=0;
        for (int j=0;j<n;j++) {
            presum=(presum+nums[j]) % k;
            if (hmap.count(presum)>0) {
                if (j-hmap[presum]>=2) return true;
            }
            else hmap[presum]=j;
        }
        return false;
    }
};

