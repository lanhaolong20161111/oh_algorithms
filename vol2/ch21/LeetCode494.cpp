class Solution {
public:
    int findTargetSumWays(vector<int>& nums,int target) {
        int n=nums.size();
        int s=0;
        for(int e:nums) s+=e;
        if (abs(target)>s) return 0;
        if ((s+target)%2==1) return 0;
        int W=(s+target)/2;
        vector<int> dp(W+1,0);
        dp[0]=1;
        for (int i=1;i<=n;i++) { 
            for (int r=W;r>=nums[i-1];r--)   //r从大到小循环（重点）
                dp[r]+=dp[r-nums[i-1]];
        }
      return dp[W];
      }
};

