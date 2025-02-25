class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans={nums[0]};
        for (int i=1;i<n;i++) {
            int curd=nums[i];
            if (curd>ans.back())        //大于ans中最大数时直接添加
                ans.push_back(curd);
            else {
                auto it=lower_bound(ans.begin(),ans.end(),curd);
                *it=curd;               //替换
            }
        }
        return ans.size();
    }
};

