class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        vector<int> tmp;
        ans.push_back(0);
        tmp.push_back(nums[n-1]);
        for(int i=n-2;i>=0;i--) {
            auto it=lower_bound(tmp.begin(),tmp.end(),nums[i]);
            ans.push_back(it-tmp.begin());
            tmp.insert(it,nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

