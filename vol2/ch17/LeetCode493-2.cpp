typedef long long LL;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        vector<LL> tmp;
        int ans=0;
        tmp.push_back(2L*nums[n-1]);
        for(int i=n-2;i>=0;i--) {
            auto it=lower_bound(tmp.begin(),tmp.end(),nums[i]);
            ans+=it-tmp.begin();
            auto it1=lower_bound(tmp.begin(),tmp.end(),2L*nums[i]);
            tmp.insert(it1,2L*nums[i]);
        }
        return ans;
    }
};

