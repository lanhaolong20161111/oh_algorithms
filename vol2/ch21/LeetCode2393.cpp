class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<long long> dp(n,0);
        dp[0]=1;
        for(int i=1;i<n;i++) {
            if(nums[i]>nums[i-1])
                dp[i]=dp[i-1]+1;
            else
                dp[i]=1;
        }
        long long ans=0;
        for(int i=0;i<n;i++) ans+=dp[i];
        return ans;
    }
};

