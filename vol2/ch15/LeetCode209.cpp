class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        vector<int> presum(n+1,0);
        presum[0]=0;
        for(int i=1;i<=n;i++)
            presum[i]=presum[i-1]+nums[i-1];
        int ans=n+1;
        int low=0,high=0;
        while(high<n) {
            if(presum[high+1]-presum[low]>=target) {
                ans=min(ans,high-low+1);
                low++;
            }
            else high++;
        }
        if(ans==n+1) return 0;
        return ans;
    }
};

