class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if (m>n) return intersect(nums2,nums1);
        unordered_map <int,int> hmap;
        for (int x:nums1) hmap[x]++;
        vector<int> ans;                    //´æ·Å´ğ°¸
        for (int y:nums2) {
            if (hmap[y]>0) {
                ans.push_back(y);
                --hmap[y];
            }
        }
        return ans;
    }
};

