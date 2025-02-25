class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> presum(n+1);				//前缀和
        vector<int> minsum(n+1);				//前缀和最小值
        presum[0]=0;
        for(int j=1;j<=n;j++)
            presum[j]=presum[j-1]+nums[j-1];
        minsum[0]=0;
        for(int j=1;j<=n;j++)
            minsum[j]=min(minsum[j-1],presum[j]);
        int ans=-0x3f3f3f3f;
        for(int j=1;j<=n;j++)
            ans=max(ans,presum[j]-minsum[j-1]);
        return ans;
    }
};

