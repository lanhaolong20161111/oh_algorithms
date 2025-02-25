class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        auto dp=vector<int>(n);
        dp[0]=1;
        int ans=dp[0];
        for(int i=1;i<n;i++) {
            dp[i]=1;
            if(nums[i]>nums[i-1])
					dp[i]=max(dp[i],dp[i-1]+1);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

