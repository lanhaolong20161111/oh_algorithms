class Solution {
public:
    int combinationSum4(vector<int>& nums,int target) {
        vector<int> dp(target+1,0);
        dp[0]=1;
        for(int j=0;j<=target;j++) {
            for(int i=1;i<=nums.size();i++) {
                if (j-nums[i-1]>=0 && dp[j]<INT_MAX-dp[j-nums[i-1]])
                    dp[j]+=dp[j-nums[i-1]];
            }
        }
        return dp[target];
    }
};

